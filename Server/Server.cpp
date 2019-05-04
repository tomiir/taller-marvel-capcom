
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
    inet_pton(AF_INET, "25.1.107.243", &serverAddr_s.sin_addr);

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
sig_atomic_t serverBrokeConnection = 0;

void Server::brokeConnection(int arg){
    serverBrokeConnection = 1;
}


void* Server::serverThread(void *clientSock_) {

    int clientSocket = *(int *) clientSock_;
    bool connected = true;

    while(true){

        signal(SIGINT, brokeConnection);
        signal(SIGQUIT, brokeConnection);

        if(serverBrokeConnection == 1){

            memset(messageToClient,0, 4096);
            strcpy(messageToClient, "El servidor se desconecto");

            if (send(clientSocket, messageToClient, strlen(messageToClient),0) < 0 ){
            }
            close(serverSocket_s);
            return nullptr;
        }

        memset(messageFromClient, 0, 4096);
        int bytesReceived = recv(clientSocket, messageFromClient, 4096,0);

        if (bytesReceived == -1) {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }
        if ( bytesReceived < 0 ) cerr << "Error al recibir el mensaje por parte del cliente " << clientSocket << endl;

        string aux = string(messageFromClient, 0, bytesReceived);
        char* received = &aux[0u];

        if( strcmp(received, "0") == 0) {
            connected = false;
            cout << "El cliente: " << clientSocket << " se desconecto" << endl;
            close(clientSocket);
            break;
        }

        if ( strcmp(received, "1") == 0){
            cout << "El cliente " << clientSocket << " esta latiendo" << endl;
        }

        if(connected and strcmp(received, "1") != 0) { //ese cmp es bastante trucho,

            cout << "Se recibio de " << clientSocket << ": " << received << endl;

            memset(messageToClient, 0, 4096);
            strcpy(messageToClient, "Se recibio el mensaje correctamente");

            send(clientSocket, messageToClient, strlen(messageToClient), 0);
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


