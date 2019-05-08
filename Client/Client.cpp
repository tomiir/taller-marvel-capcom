//
// Created by fer on 27/04/19.
//

#include <csignal>
#include "Client.h"
#include "../utils/Logger/Logger.h"

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

queue<string> queueRecv;

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

    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ){
        logger->Log("Fallo la conexion con el servidor", ERROR, strerror(errno));
        return false;
    }
    cout << "Conectando con el servidor..." << endl;
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
    future<int> scanning = async(scanf,"%s",messageFromInput);
    chrono::milliseconds waitTime (2000);

    while(scanning.wait_for(waitTime) == future_status::timeout){

        if(clientBrokeConnection){
            beating = false;
            this->Disconnect();
            exit(0);
        }
        Send(BEAT);
    }

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

    memset(messageFromServer, 0, 4096);
    int bytesReceived = recv(serverSocket_c, messageFromServer, 4096, 0);

    if(bytesReceived == -1){
        checkRecvFromServerError();
    }
    string messageReceived = string(messageFromServer, 0, bytesReceived);

    queueRecv.push(messageReceived);

    logger->Log("Se recibio correctamente del server el mensaje: " + messageReceived, NETWORK, "");

    return messageFromServer;
}

void* Client::render(void *arg) {

    string messageReceived = queueRecv.front();
    string view = messageReceived.substr(0,2);

    if(view == "00"){ //view selected

        //zIndex
        string greySquaredSelectedt11 = messageReceived.substr(2,3);
        string greySquaredSelectedt12 = messageReceived.substr(3,4);
        string greySquaredSelectedt21 = messageReceived.substr(4,5);
        string greySquaredSelectedt22 = messageReceived.substr(5,6);

        viewSelectCharacter->updateGreySquares(greySquaredSelectedt11, greySquaredSelectedt12, greySquaredSelectedt21, greySquaredSelectedt22 );

        //0  1
        //2  3
        string selectT1 = messageReceived.substr(6,8);
        string selectT2 = messageReceived.substr(8,10);

        viewSelectCharacter->updateSelects(selectT1, selectT2);

        //personaje,zIndex
        string characterUpRight = messageReceived.substr(10,14);
        string characterDownRight = messageReceived.substr(14,18);
        string characterUpLeft = messageReceived.substr(18,22);
        string characterDownLeft = messageReceived.substr(22,26);

        viewSelectCharacter->updateCharactersImages(characterUpRight, characterDownRight, characterUpLeft, characterDownLeft);

        //selected or not
        string selected = messageReceived.substr(26,27);
        viewSelectCharacter->updateSelected(selected);
        viewSelectCharacter->render();
        queueRecv.pop();

    }
    if(view == "01") { //view fight


    }
}

void* Client::sendEventToServer(void* arg){

    CLogger* logger = CLogger::GetLogger();

    while(true){
        SDL_Event event;
        SDL_PollEvent(&event);
        //timmer para no enviar tantos eventos
        char* mapEvent = currentMapper()->map(event);
        if (event.type == SDL_QUIT) {
            logger -> Log("Saliendo del juego", INFO, "");
            connect2 = false;
            break;
        }
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
    Disconnect();
}

void Client::setMappers(Mapper* mapperSelect_, Mapper* mapperFight_){

    currentMapper = mapperSelect_;
    notCurrentMapper = mapperFight_;
}
