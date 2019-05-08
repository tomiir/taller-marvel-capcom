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

char* Client::update() {

    memset(messageFromServer, 0, 4096);
    int bytesReceived = recv(serverSocket_c, messageFromServer, 4096, 0);

    if(bytesReceived == -1){
        checkRecvFromServerError();
    }

    string messageReceived = string(messageFromServer, bytesReceived);
    logger->Log("Se recibio correctamente del server el mensaje: " + messageReceived, NETWORK, "");

    return &messageReceived[0u]; //SI TIRA SEGSEV ES POR ESTA COSA RARA
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