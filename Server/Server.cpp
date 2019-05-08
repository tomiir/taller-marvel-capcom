
#include <csignal>
#include <queue>
#include "Server.h"

//----SERVER VARIABLES----
int serverSocket_s;
struct sockaddr_in serverAddr_s;
socklen_t serverSize_s;

//----CLIENT VARIABLES----

int clientSocket[MAXCLIENTS];
struct sockaddr_in clientAddr[MAXCLIENTS];
socklen_t clientSize[MAXCLIENTS];

char messageFromClient[4096];
char messageToClient[4096];

queue<string> serverQueue;



Server::Server() {

    CLogger* logger = CLogger::GetLogger();
    serverSocket_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket_s == -1) {
        logger->Log( "No se pudo crear el socket del servidor, saliendo..." , ERROR, strerror(errno));
    }

    serverAddr_s.sin_family = AF_INET;
    serverAddr_s.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0" , &serverAddr_s.sin_addr);

    int option = 1;
    if (setsockopt(serverSocket_s,SOL_SOCKET,SO_REUSEADDR,&option,sizeof(int)) == -1) {
        logger -> Log("Error al setear opciones del socket, saliendo...", ERROR, strerror(errno));
        logger->closeLogger();
        exit(1);
    }

    if (bind(serverSocket_s, (sockaddr*)&serverAddr_s, sizeof(serverAddr_s)) < 0 ){
        logger->Log( "No se puede bindear al puerto o IP" , ERROR, strerror(errno));
        logger->closeLogger();
        exit(1);
    }
}

void Server::checkSendToClientError(int clientSock) {

    CLogger* logger = CLogger::GetLogger();
    switch(errno) {

        case ECONNRESET:
            logger->Log( "El cliente cerro la conexion" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case EINTR:
            logger->Log( "Una señal interrumpio el send antes de enviar el mensaje" , ERROR, strerror(errno));
            break;

        case EIO:
            logger->Log( "Hubo un problema en la red o en el transporte" , ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log( "El cliente no esta conectado" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case EPIPE:
            logger->Log( "Se recibio un SIGPIPE del cliente" , ERROR, strerror(errno));
            close(clientSock);
            logger->closeLogger();
            exit(0);
    }
}

void Server::checkRecvFromClientError(int clientSock) {

    CLogger* logger = CLogger::GetLogger();
    switch(errno) {

        case ECONNREFUSED:
            logger->Log( "El cliente rechazo la conexion" , ERROR, strerror(errno));
            close(clientSock);
            break;

        case EINTR:
            logger->Log( "Una señal interrumpio el recv antes de recibir el mensaje" , ERROR, strerror(errno));
            break;

        case ENOMEM:
            logger->Log( "No se pudo alocar memoria para el mensaje" , ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log( "El cliente no esta conectado" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case ENOTSOCK:
            logger->Log( "Problema con el socket del cliente, mal configurado" , ERROR, strerror(errno));
            break;
    }
}

sig_atomic_t serverBrokeConnection = 0;

void Server::brokeConnection(int arg){
    serverBrokeConnection = 1;
}


void Server::Send(int clientSock){

    if (send(clientSock, messageToClient, strlen(messageToClient),0) == -1 ){
        checkSendToClientError(clientSock);
    }
    memset(messageToClient,0, 4096);
}

string Server::update(int clientSock){

    memset(messageFromClient, 0, 4096);
    int bytesReceived = recv(clientSock, messageFromClient, 4096,0);

    if (bytesReceived == -1) {
        checkRecvFromClientError(clientSock);
    }

    string received = string(messageFromClient, 0, bytesReceived);
    return received;
}

void* Server::serverThread(void *clientSock_) {

    int clientSock = *(int *) clientSock_;
    CLogger* logger = CLogger::GetLogger();

    while(true){

        signal(SIGINT, brokeConnection);
        signal(SIGTSTP, brokeConnection);
        signal(SIGQUIT, brokeConnection);

        if(serverBrokeConnection == 1){

            memset(messageToClient,0, 4096);
            strcpy(messageToClient, "El servidor se desconecto");
            Send(clientSock);
            close(serverSocket_s);
            return nullptr;
        }

        string received = update(clientSock);

        if( strcmp(received.c_str(), "0") == 0) {
            logger->Log( "El cliente: " + to_string(clientSock) + " se desconecto" , NETWORK, "");
            close(clientSock);
            break;
        }

        if ( strcmp(received.c_str(), "1") == 0){
            logger->Log( "El cliente " + to_string(clientSock) + " esta latiendo" , NETWORK, "");
            memset(messageFromClient,0,4096);
        }


        if(strcmp(received.c_str(), "1") != 0) { //ese cmp es bastante trucho,

            serverQueue.push(received);
            logger->Log( "Se recibio de " + to_string(clientSock) + ": " + received , NETWORK, "");
            memset(messageToClient,0, 4096);
            strcpy(messageToClient, "Se recibio el mensaje correctamente");
            Send(clientSock);
        }
    }
}


void Server::clientConnected(sockaddr_in clientAddr_){

    CLogger* logger = CLogger::GetLogger();
    char clientIp[NI_MAXHOST];
    char server[NI_MAXSERV];
    memset(clientIp, 0, NI_MAXHOST);
    memset(server, 0, NI_MAXSERV);

    int canGetInfo = getnameinfo((sockaddr *) &clientAddr_, sizeof(clientAddr_),
                                 clientIp, NI_MAXHOST, server, NI_MAXSERV, 0);

    if (canGetInfo == 0) {
        inet_ntop(AF_INET, &clientAddr_.sin_addr, clientIp, NI_MAXHOST);
        logger->Log( "El cliente " + string(clientIp) + " se conecto al server: " + server , NETWORK, "");
    }
}

void Server::connect() {

    CLogger* logger = CLogger::GetLogger();

    if(listen(serverSocket_s, MAXCLIENTS) < 0 ) {
        logger->Log( "No se puede escuchar", ERROR, strerror(errno));
    }

    int clientsIter = 0;
    pthread_t clientThreads[4];

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        clientSize[clientsIter] = sizeof(clientAddr[clientsIter]);
        clientSocket[clientsIter] = accept(serverSocket_s, (struct sockaddr*)&clientAddr[clientsIter], &clientSize[clientsIter]);
        clientConnected(clientAddr[clientsIter]);
    }
    logger->Log( "Ya se conectaron los clientes" , INFO, "");
    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++) {
        memset(messageToClient,0, 4096);
        strcpy(messageToClient, "connected");
        Send(clientSocket[clientsIter]);
    }

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        int readThread = pthread_create(&clientThreads[clientsIter], nullptr, serverThread, &clientSocket[clientsIter]);
        if(readThread != 0) {
            logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
        }
    }

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        pthread_join(clientThreads[clientsIter], nullptr);
    }
    logger->Log( "Se desconectaron todos los clientes, saliendo del juego." , INFO, "");
    logger->closeLogger();
    close(serverSocket_s);

}

void* Server::popQueue(void* arg){
    CLogger* logger = CLogger::GetLogger();
    string messagePop = serverQueue.front();
    logger->Log("Se desencolo el mensaje: " + messagePop, INFO, "");
    cout << "Se desencolo el mensaje: " + messagePop << endl;
    serverQueue.pop();
}


