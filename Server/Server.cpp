
#include <csignal>
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



Server::Server() {

    serverSocket_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket_s == -1) {
        cerr << "No se pudo crear el socket del servidor, saliento" << endl;
    }

    serverAddr_s.sin_family = AF_INET;
    serverAddr_s.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0" , &serverAddr_s.sin_addr);

    int option = 1;
    if (setsockopt(serverSocket_s,SOL_SOCKET,SO_REUSEADDR,&option,sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    if (bind(serverSocket_s, (sockaddr*)&serverAddr_s, sizeof(serverAddr_s)) < 0 ){
        cout << "Can't bind to IP/port" << endl;
        exit(1);
    }
}

void Server::checkSendToClientError(int clientSock) {

    switch(errno) {

        case ECONNRESET:
            cout << "El cliente cerro la conexion" << endl;
            close(clientSock);
            break;
        case EINTR:
            cout << "Una señal interrumpio el send antes de enviar el mensaje" << endl;
            break;
        case EIO:
            cout << "Hubo un problema en la red o en el transporte" << endl;
            break;
        case ENOTCONN:
            cout << "El cliente no esta conectado" << endl;
            close(clientSock);
            break;
        case EPIPE:
            cout << "Se recibio un SIGPIPE del cliente" << endl;
            close(clientSock);
            exit(0);
    }
}

void Server::checkRecvFromClientError(int clientSock) {

    switch(errno) {
        case ECONNREFUSED:
            cout << "El cliente rechazo la conexion" << endl;
            close(clientSock);
            break;
        case EINTR:
            cout << "Una señal interrumpio el recv antes de recibir el mensaje" << endl;
            break;
        case ENOMEM:
            cout << "No se pudo alocar memoria para el mensaje" << endl;
            break;
        case ENOTCONN:
            cout << "El cliente no esta conectado" << endl;
            close(clientSock);
            break;
        case ENOTSOCK:
            cout << "Problema con el socket del cliente, mal configurado" << endl;
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
            cout << "El cliente: " << clientSock << " se desconecto" << endl;
            close(clientSock);
            break;
        }

        if ( strcmp(received.c_str(), "1") == 0){
            cout << "El cliente " << clientSock << " esta latiendo" << endl;
            memset(messageFromClient,0,4096);
        }


        if(strcmp(received.c_str(), "1") != 0) { //ese cmp es bastante trucho,

            cout << "Se recibio de " << clientSock << ": " << string(received) << endl;
            memset(messageToClient,0, 4096);
            strcpy(messageToClient, "Se recibio el mensaje correctamente");
            Send(clientSock);
        }
    }
}


void clientConnected(sockaddr_in clientAddr_){

    char clientIp[NI_MAXHOST];
    char server[NI_MAXSERV];
    memset(clientIp, 0, NI_MAXHOST);
    memset(server, 0, NI_MAXSERV);

    int canGetInfo = getnameinfo((sockaddr *) &clientAddr_, sizeof(clientAddr_),
                                 clientIp, NI_MAXHOST, server, NI_MAXSERV, 0);

    if (canGetInfo == 0) {
        inet_ntop(AF_INET, &clientAddr_.sin_addr, clientIp, NI_MAXHOST);
        cout << "El cliente " << clientIp << " se conecto al server: " << server << endl;
    }
}
void Server::Listen() {

    if(listen(serverSocket_s, MAXCLIENTS) < 0 ) {
        cerr << "No se puede escuchar";
    }

    int clientsIter = 0;
    pthread_t clientThreads[4];

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        clientSize[clientsIter] = sizeof(clientAddr[clientsIter]);
        clientSocket[clientsIter] = accept(serverSocket_s, (struct sockaddr*)&clientAddr[clientsIter], &clientSize[clientsIter]);
        clientConnected(clientAddr[clientsIter]);
    }
    cout << "Ya se conectaron los clientes" << endl;
    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++) {
        memset(messageToClient,0, 4096);
        strcpy(messageToClient, "connected");
        Send(clientSocket[clientsIter]);
    }

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        int canCreateThread = pthread_create(&clientThreads[clientsIter], nullptr, serverThread, &clientSocket[clientsIter]);
        if(canCreateThread != 0) {
            printf("Fallo al crear el thread");
        }
    }

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        pthread_join(clientThreads[clientsIter], nullptr);
    }

    cout << "Se desconectaron todos los clientes, saliendo del juego." << endl;
    close(serverSocket_s);

}


