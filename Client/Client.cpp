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

char messageFromServer[4096];
char messageToSever[4096];
char messageFromInput[4096];
bool connect2 = true;

queue<char*> queueRecv;

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

    logger->Log("Se envio correctamente el mensaje: " + string(message) , NETWORK, "");


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


void* Client::recvFromServer(void* arg) {

    CLogger* logger = CLogger::GetLogger();

    while(connect2){
        memset(messageFromServer, 0, 4096);

        //Aca habrai que chequear que si no recibe por un tiempo se da por uerto el server(seria como el heartbeat)
        int bytesReceived = recv(serverSocket_c, messageFromServer, 4096, 0);

        if(bytesReceived == -1){
            checkRecvFromServerError();
            break;  //No estoy seguro si habria que hacer este break.
        }
        //string messageReceived = string(messageFromServer, 0, bytesReceived);

        queueRecv.push(messageFromServer);

        logger->Log("Se recibio correctamente del server el mensaje: " + string(messageFromServer), NETWORK, "");
    }

}

void* Client::render(void *arg) {

    //Aca habria antes que cargar las views
    CLogger *logger = CLogger::GetLogger();
    logger->Log("Inicializando juego", INFO, "");
    JsonConfigs *config = JsonConfigs::getJson();

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    std::string aux = config->getTitle();
    const char *title = aux.c_str();
    const int FPS = config->getFPS();

    Game *game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
//        Uint32 start;

//        start = SDL_GetTicks();
//        try { game->tick(); }
//        catch (int e) { break; }
//
//        if ((1000 / FPS) > (SDL_GetTicks() - start)) {
//            SDL_Delay((1000 / FPS) - (SDL_GetTicks() - start));
//        }






    //Aca empieza el loop que va a ir renderizando. Las view ay deberian estar cargadas y se renderiza lo que se tenga que renderizar
    while(connect2){


        char* messageReceived = queueRecv.front();
        char view[] = {messageReceived[0], messageReceived[1], '\0'};

        if(strcmp(view, "00") == 0){ //view selected

            //zIndex
            char greySquaresSelected[] = {messageReceived[2], messageReceived[3], messageReceived[4], messageReceived[5], '\0'};

            game->updateGreySquares(greySquaresSelected);

            //0  1
            //2  3
            char selectT1[] = {messageReceived[6], messageReceived[7], '\0'};
            char selectT2[] = {messageReceived[8], messageReceived[9], '\0'};

            game->updateSelects(selectT1, selectT2);

            //personaje,zIndex
            char selected_1[] = {messageReceived[10], messageReceived[11], messageReceived[12], '\0'};
            char selected_2[] = {messageReceived[13], messageReceived[14], messageReceived[15], '\0'};

            game->updateCharactersImages(selected_1, selected_2);


            game->render();
            queueRecv.pop();

        }
        if(strcmp(view, "01") == 0) { //view fight


        }
    }

    game->clean();

}

void* Client::sendEventToServer(void* arg){

    CLogger* logger = CLogger::GetLogger();

    while(true){
        SDL_Event event;
        SDL_PollEvent(&event);
        //timmer para no enviar tantos eventos
        //Habria que ver como saber que hay que cambiar el mapper y hacerlo. Tambien se podria usar un solo mapper y fue.
        char* mapEvent = currentMapper->map(event);
        if (event.type == SDL_QUIT) {
            logger -> Log("Saliendo del juego", INFO, "");
            connect2 = false;
            break;
        }
        //Esto no se tendria que mandar a penas cae un evento. Cada tantos milisegundos tendria que crearse un char* mas grande unido por varias events y enviarse
        ssize_t bytesSent = send(serverSocket_c, mapEvent, sizeof(mapEvent), 0);
        if(bytesSent < 0) checkSendToServerError();
    }
}

void Client::Initialice() {

    pthread_t sendEventThread;
    pthread_t recvFromServerThread;
    pthread_t renderThread;

    pthread_create(&sendEventThread, nullptr, &sendEventToServer, nullptr);
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

    Mapper* aux = currentMapper;
    currentMapper = notCurrentMapper;
    notCurrentMapper = aux;

}
