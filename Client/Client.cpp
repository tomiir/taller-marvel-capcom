//
// Created by fer on 27/04/19.
//

#include "Client.h"


#define NOBEAT (char*)"0"
#define MESSAGEFROMSERVERLEN 54
#define MESSAGEFROMSERVERLEN2 5


int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

pthread_t sendEventThread;
pthread_t recvFromServerThread;
pthread_t renderThread;

char messageFromServer[MESSAGEFROMSERVERLEN];
char messageToKnowTheTeam[MESSAGEFROMSERVERLEN2];

bool connected = true;
bool serverConnected = true;
bool serverDown = false;

queue<string> queueRecv;

Game *game;

Mapper* currentMapper;
Mapper* notCurrentMapper;


void Client::configServer(const char* serverIp, uint16_t serverPort){

    serverSocket_c = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    serverAddr_c.sin_family = AF_INET;
    serverAddr_c.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp, &serverAddr_c.sin_addr);
    serverSize_c = sizeof(serverAddr_c);
}


Client::Client(const char* serverIp, uint16_t serverPort) {

    configServer(serverIp, serverPort);
}


void Client::Disconnect() {

    Send(NOBEAT);
    logger->Log("Desconectando al cliente", NETWORK, "");
    close(serverSocket_c);
}


bool Client::Connect() {

    cout << "Conectando con el servidor..." << endl;
    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ){
        logger->Log("Fallo la conexion con el servidor", ERROR, strerror(errno));
        cout << "El servidor no esta activo" << endl;
        return false;
    }
    cout << "Se ha establecido la conexion" << endl;
    return true;
}


void Client::checkRecvFromServerError(){
    CLogger* logger = CLogger::GetLogger();

    switch(errno) {

        case ECONNREFUSED:
            logger->Log("El server rechazo la conexion", NETWORK, strerror(errno));
            close(serverSocket_c);
            break;

        case EINTR:
            logger->Log("Una señal interrumpio el recv antes de recibir el mensaje", ERROR, strerror(errno));
            break;

        case ENOMEM:
            logger->Log("No se pudo alocar memoria para el mensaje", ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log("El server no esta conectado", NETWORK, strerror(errno));
            close(serverSocket_c);
            break;

        case ENOTSOCK:
            logger->Log("Problema con el socket del server, mal configurado", ERROR, strerror(errno));
            break;
    }
}


void Client::checkSendToServerError(){
    CLogger* logger = CLogger::GetLogger();

    switch(errno) {

        case ECONNRESET:
            logger->Log("El server cerro la conexion", NETWORK, strerror(errno));
            close(serverSocket_c);
            break;

        case EINTR:
            logger->Log("Una señal interrumpio el send antes de enviar el mensaje", ERROR, strerror(errno));
            break;

        case EIO:
            logger->Log("Hubo un problema en la red o en el transporte", ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log("El server no esta conectado", NETWORK, strerror(errno));
            close(serverSocket_c);
            break;

        case EPIPE:
            close(serverSocket_c);
            //aca tendria que seguir intentando reconectarse al server
            exit(0);
    }
}


void Client::Send(char* message) {

    signal(SIGPIPE, SIG_IGN);

    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);

    if(bytesSent == -1){
        checkSendToServerError();
    }


}


char *Client::messageFromServerReceived(){

    memset(messageToKnowTheTeam, 0, MESSAGEFROMSERVERLEN2);

    int bytesReceived = recv(serverSocket_c, messageToKnowTheTeam, MESSAGEFROMSERVERLEN2, 0);

    if(bytesReceived == -1){
        checkRecvFromServerError();
    }

    return messageToKnowTheTeam;
}

void messageBox(){
    SDL_ShowSimpleMessageBox (SDL_MESSAGEBOX_INFORMATION ,
                              "Desconexion",
                              "El server se ha desconectado",
                              NULL);
}

void* timerClient(void * arg){

    sleep(5);

    cout << "Server desconectado" << endl;
    serverConnected = false;

    game->renderDisconnected();

}


void* Client::recvFromServer(void* arg) {

    CLogger* logger = CLogger::GetLogger();

    while(connected){

        pthread_t timerThread;
        int readThread = pthread_create(&timerThread, nullptr, timerClient, nullptr);

        if(readThread !=0){
            logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
        }

        memset(messageFromServer, 0, MESSAGEFROMSERVERLEN);

        //Aca habrai que chequear que si no recibe por un tiempo se da por puerto el server(seria como el heartbeat)
        int bytesReceived = recv(serverSocket_c, messageFromServer, MESSAGEFROMSERVERLEN, 0);

        pthread_cancel(timerThread);
        pthread_detach(timerThread);

        serverConnected = true;

        if(bytesReceived == -1){
            checkRecvFromServerError();
        }

        if(strcmp(messageFromServer, "serverDisconnect") == 0){
            cout << "El server se cayo" << endl;
            serverConnected = false;
            serverDown = true;
            while(!queueRecv.empty()){
                queueRecv.pop();
            }
            messageBox();
            close(serverSocket_c);
            pthread_cancel(sendEventThread);
            pthread_cancel(renderThread);
            cout << "Desconectando..." << endl;
            pthread_exit(0);
        }
        string message = (string)(messageFromServer);
        queueRecv.push(message);
    }
    return nullptr;

}


void* Client::render(void *arg) {

    bool fight_view = false;
    int viewNumber = 0;
    char oldView [] = {'0','0','\n'};
   //Aca empieza el loop que va a ir renderizando. Las view ay deberian estar cargadas y se renderiza lo que se tenga que renderizar
    while(connected){

        if(queueRecv.empty()) continue;

        string message = queueRecv.front();
        const char* messageReceived = message.c_str();
        char view[] = {messageReceived[0], messageReceived[1], '\0'};

        if (strcmp(view, oldView) == 1){
            changeCurrentMapper();
            viewNumber += 1;
            cout<<viewNumber;
            game->changeView(viewNumber);
            strncpy(oldView, view, 2);
        }



        if(strcmp(view, "00") == 0 and viewNumber == 0){ //view selected

            //Te devuelve 1 en el cuadrado gris que si se tenga que renderizar
            char greySquaresSelected[] = {messageReceived[2], messageReceived[3], messageReceived[4], messageReceived[5], '\0'};


            //0  1
            //2  3
            char selectT1[] = {messageReceived[6], messageReceived[7], '\0'};
            char selectT2[] = {messageReceived[8], messageReceived[9], '\0'};


            //Esto setea los selected de ambos equipos para saber que imagenes de los costados renderizar
            char selected_1[] = {messageReceived[10], messageReceived[11], '\0'};
            char selected_2[] = {messageReceived[12], messageReceived[13], '\0'};

            game->updateSelects(selectT1, selectT2);
            game->updateCharactersImages(selected_1, selected_2);
            game->updateGreySquares(greySquaresSelected);

            game->render();
            queueRecv.pop();

        }

        if(strcmp(view, "01") == 0 or viewNumber == 1) { //view fight


            //Recibo las nuevas posiciones de los backgrounds y los actaulizo
            char posFloor_x[] = {messageReceived[2], messageReceived[3], messageReceived[4], messageReceived[5], '\0'};
            char posFloor_y[] = {messageReceived[6], messageReceived[7], messageReceived[8], '\0'};

            char posMoon_x[] = {messageReceived[9], messageReceived[10], messageReceived[11], messageReceived[12], '\0'};
            char posMoon_y[] = {messageReceived[13], messageReceived[14], messageReceived[15], '\0'};

            char posGalaxy_x[] = {messageReceived[16], messageReceived[17], messageReceived[18], messageReceived[19], '\0'};
            char posGalaxy_y[] = {messageReceived[20], messageReceived[21], messageReceived[22], '\0'};

            game->UpdateBackgrounds(posFloor_x, posFloor_y, posMoon_x, posMoon_y, posGalaxy_x, posGalaxy_y);

            //Recibo las nuevas posiciones de los characters y sus estados y lo actualizo
            char posCharTeam1_x[] = {messageReceived[23], messageReceived[24], messageReceived[25], messageReceived[26], '\0'};
            char posCharTeam1_y[] = {messageReceived[27], messageReceived[28], messageReceived[29], messageReceived[30], '\0'};
            char stateCharTeam1 = messageReceived[31];

            char posCharTeam2_x[] = {messageReceived[32], messageReceived[33], messageReceived[34], messageReceived[35], '\0'};
            char posCharTeam2_y[] = {messageReceived[36], messageReceived[37], messageReceived[38], messageReceived[39], '\0'};
            char stateCharTeam2 = messageReceived[40];

            char flipChar1 = messageReceived[41];
            char flipChar2 = messageReceived[42];

            char currentCharT1 = messageReceived[43];
            char currentCharT2 = messageReceived[44];


            game->updateCharacters(posCharTeam1_x, posCharTeam1_y, stateCharTeam1, flipChar1, currentCharT1,
                    posCharTeam2_x, posCharTeam2_y, stateCharTeam2, flipChar2, currentCharT2);

            char ten[] = {messageReceived[45],'\0'};
            char unity[] = {messageReceived[46],'\0'};
            char round[] = {messageReceived[47],'\0'};

            game->updateTime(ten,unity,round);

            char lifeTeam1[] = {messageReceived[48], messageReceived[49], messageReceived[50], '\0'};
            char lifeTeam2[] = {messageReceived[51], messageReceived[52], messageReceived[53], '\0'};


            game->updateLife(lifeTeam1, lifeTeam2);

            game->render();
            queueRecv.pop();
        }

        if(strcmp(view, "02") == 0 or viewNumber == 2){
            char winners[] = {messageReceived[3],messageReceived[4],'\0'};
            game->updateWinners(winners);
            game->render();
            queueRecv.pop();
        }

    }
    game->clean();
    return nullptr;
}


void* Client::sendEventToServer(void* arg){

    signal(SIGPIPE, SIG_IGN);

    CLogger* logger = CLogger::GetLogger();


    int speed = 60;
    Uint32 start;

    string mapEvent;

    while(true){

        start = SDL_GetTicks();

        if (!serverConnected){
            if(serverDown) break;
        }


        SDL_Event event;
        SDL_PollEvent(&event);

        //timmer para no enviar tantos eventos
        mapEvent = currentMapper->map(event);
        if (event.type == SDL_QUIT) {
            logger -> Log("Saliendo del juego", INFO, "");
            connected = false;
            pthread_exit(nullptr);
        }


        ssize_t bytesSent = send(serverSocket_c, mapEvent.c_str(), sizeof(mapEvent.c_str()), 0);
        if(bytesSent < 0) checkSendToServerError();

        if ((1000 / speed) > (SDL_GetTicks() - start)) {
            SDL_Delay((1000 / speed) - (SDL_GetTicks() - start));
        }


    }
}


void Client::Initialice() {

    //Aca habria antes que cargar las views
    logger->Log("Inicializando juego", INFO, "");
    JsonConfigs *config = JsonConfigs::getJson();

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    std::string aux2 = config->getTitle();
    const char *title = aux2.c_str();

    game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);


    int error = pthread_create(&sendEventThread, nullptr, &sendEventToServer, nullptr);
    if(error == -1) cout << "SE ROMPIO " << endl;
        //Si el send finaliza, esto finaliza.
    pthread_create(&recvFromServerThread, nullptr, &recvFromServer, nullptr);
    pthread_create(&renderThread, nullptr, &render, nullptr);


    pthread_join(sendEventThread, nullptr);
    pthread_cancel(recvFromServerThread);
    pthread_cancel(renderThread);    //igual si se cierra en realidad habria que tomar mas medidas como limpiar el clearWindow que por ahi se pueden tomar en disconnect
    Disconnect();
}


void Client::setMappers(Mapper* mapperSelect_, Mapper* mapperFight_){

    currentMapper = mapperSelect_;
    notCurrentMapper = mapperFight_;
}


void Client::changeCurrentMapper(){

    Mapper* aux = currentMapper;
    currentMapper = notCurrentMapper;
    notCurrentMapper = aux;

}

