//
// Created by fer on 27/04/19.
//

#include "Client.h"
#include "../Json/JsonConfigs.h"
#include "../model/Game/Game.h"

#define NOBEAT (char*)"0"
#define BEAT (char*)"1"

//----SERVER VARIABLES----
int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

char messageFromServer[39];
char messageToSever[4096];
char messageFromInput[4096];
char aux[5];

bool connect2 = true;

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
    beating = true;
}

void Client::Disconnect() {

    Send( NOBEAT );
    logger->Log("Desconectando al cliente", NETWORK, "");
    close(serverSocket_c);
    connect2 = false;
}


bool Client::Connect() {

    cout << "Conectando con el servidor..." << endl;
    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ){
        logger->Log("Fallo la conexion con el servidor", ERROR, strerror(errno));
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


    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);

    if(bytesSent == -1){
        checkSendToServerError();
    }

    //logger->Log("Se envio correctamente el mensaje: " + string(message) , NETWORK, "");


}

sig_atomic_t clientBrokeConnection = 0;

void Client::brokeConnection(int arg){
    clientBrokeConnection = 1;
}


void Client::hearthBeat(){

    signal(SIGINT, brokeConnection);
    signal(SIGQUIT, brokeConnection);
    signal(SIGTSTP, brokeConnection);
    signal(SIGPIPE, SIG_IGN);


    memset(messageFromInput, 0, 4096);
    //future<int> scanning = async(scanf,"%s",messageFromInput);
    //chrono::milliseconds waitTime (2000);

    scanf("%s", messageFromInput);

    //while(scanning.wait_for(waitTime) == future_status::timeout){

        if(clientBrokeConnection){
            beating = false;
            this->Disconnect();
            exit(0);
        }
        //Send(BEAT);
    //}

    if(strcmp(messageFromInput, "quit") == 0) {
        beating = false;
        this->Disconnect();
        exit(0);
    }

    Send(messageFromInput);
}

bool Client::isBeating() {

    return beating;
}






char *Client::messageFromServerReceived(){

    memset(aux, 0, 5);

    int bytesReceived = recv(serverSocket_c, aux, 5, 0);

    if(bytesReceived == -1){
        checkRecvFromServerError();
    }

    return aux;
}






void* Client::recvFromServer(void* arg) {


    while(connect2){
        memset(messageFromServer, 0, 39);

        //Aca habrai que chequear que si no recibe por un tiempo se da por uerto el server(seria como el heartbeat)
        int bytesReceived = recv(serverSocket_c, messageFromServer, 39, 0);

        if(bytesReceived == -1){
            checkRecvFromServerError();
            break;  //No estoy seguro si habria que hacer este break.
        }
        //string messageReceived = string(messageFromServer, 0, bytesReceived);

        string message = (string)(messageFromServer);
        queueRecv.push(message);

    }

}

void* Client::render(void *arg) {


   //Aca empieza el loop que va a ir renderizando. Las view ay deberian estar cargadas y se renderiza lo que se tenga que renderizar
    while(connect2){

        if(queueRecv.empty()) continue;

        string message = queueRecv.front();
        const char* messageReceived = message.c_str();
        char view[] = {messageReceived[0], messageReceived[1], '\0'};

        if(strcmp(view, "00") == 0){ //view selected

            //Te devuelve 1 en el cuadrado gris que si se tenga que renderizar
            char greySquaresSelected[] = {messageReceived[2], messageReceived[3], messageReceived[4], messageReceived[5], '\0'};

            game->updateGreySquares(greySquaresSelected);

            //0  1
            //2  3
            char selectT1[] = {messageReceived[6], messageReceived[7], '\0'};
            char selectT2[] = {messageReceived[8], messageReceived[9], '\0'};

            game->updateSelects(selectT1, selectT2);

            //Esto setea los selected de ambos equipos para saber que imagenes de los costados renderizar
            char selected_1[] = {messageReceived[10], messageReceived[11], messageReceived[12], '\0'};
            char selected_2[] = {messageReceived[13], messageReceived[14], messageReceived[15], '\0'};

            game->updateCharactersImages(selected_1, selected_2);

            game->render();
            queueRecv.pop();

        }
        if(strcmp(view, "01") == 0) { //view fight

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
            char posCharTeam1_y[] = {messageReceived[27], messageReceived[28], messageReceived[29], '\0'};
            char stateCharTeam1 = messageReceived[30];

            char posCharTeam2_x[] = {messageReceived[31], messageReceived[32], messageReceived[33], messageReceived[34], '\0'};
            char posCharTeam2_y[] = {messageReceived[35], messageReceived[36], messageReceived[37], '\0'};
            char stateCharTeam2 = messageReceived[38];

            game->updateCharacters(posCharTeam1_x, posCharTeam1_y, stateCharTeam1, posCharTeam2_x, posCharTeam2_y, stateCharTeam2);

            //Actualizo el flip para que queden las imagenes mirando para el lado correcto
            game->updateFlip();

            game->render();
            queueRecv.pop();
        }
    }
    game->clean();
}




void* Client::sendEventToServer(void* arg){

    CLogger* logger = CLogger::GetLogger();


    int speed = 60;
    Uint32 start;

    string mapEvent;

    while(true){

        start = SDL_GetTicks();
        if (game->haveToChangeView()){
            changeCurrentMapper();
            game->changeView();
        }

        SDL_Event event;
        SDL_PollEvent(&event);
        //timmer para no enviar tantos eventos
        //Habria que ver como saber que hay que cambiar el mapper y hacerlo. Tambien se podria usar un solo mapper y fue.
        mapEvent = currentMapper->map(event);
        if (event.type == SDL_QUIT) {
            logger -> Log("Saliendo del juego", INFO, "");
            connect2 = false;
            break;
        }


        if ((1000 / speed) > (SDL_GetTicks() - start)) {
            SDL_Delay((1000 / speed) - (SDL_GetTicks() - start));
        }


        //Esto no se tendria que mandar a penas cae un evento. Cada tantos milisegundos tendria que crearse un char* mas grande unido por varias events y enviarse
        ssize_t bytesSent = send(serverSocket_c, mapEvent.c_str(), sizeof(mapEvent.c_str()), 0);
        if(bytesSent < 0) checkSendToServerError();


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
    const int FPS = config->getFPS();

    game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

//        Uint32 start;

//        start = SDL_GetTicks();
//        try { game->tick(); }
//        catch (int e) { break; }
//
//        if ((1000 / FPS) > (SDL_GetTicks() - start)) {
//            SDL_Delay((1000 / FPS) - (SDL_GetTicks() - start));
//        }


    pthread_t sendEventThread;
    pthread_t recvFromServerThread;
    pthread_t renderThread;

    int error = pthread_create(&sendEventThread, nullptr, &sendEventToServer, nullptr);
    if(error == -1) cout << "SE ROMPIO " << endl;
        //Si el send finaliza, esto finaliza.
    pthread_create(&recvFromServerThread, nullptr, &recvFromServer, nullptr);
    pthread_create(&renderThread, nullptr, &render, nullptr);


    pthread_join(sendEventThread, nullptr);
    pthread_cancel(recvFromServerThread);
    pthread_cancel(renderThread);    //igual si se cierra en realidad habria que tomar mas medidas como limpiar el render que por ahi se pueden tomar en disconnect
    Disconnect();
}

void Client::setMappers(Mapper* mapperSelect_, Mapper* mapperFight_){

    currentMapper = mapperSelect_;
    notCurrentMapper = mapperFight_;
}

void Client::changeCurrentMapper(){

    Mapper* aux2 = currentMapper;
    currentMapper = notCurrentMapper;
    notCurrentMapper = aux2;

}

