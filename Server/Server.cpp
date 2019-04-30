//
// Created by fer on 27/04/19.
//

#include "Server.h"
//----SERVER VARIABLES----
int serverSocket_s;
struct sockaddr_in serverAddr_s;
socklen_t serverSize_s;

//----CLIENT VARIABLES----
int clientSocket_s;
struct sockaddr_in clientAddr_s;
socklen_t clientSize_s = sizeof(clientAddr_s);


Server::Server() {

    serverSocket_s = socket(AF_INET, SOCK_STREAM, 0);
    if( serverSocket_s == -1 ){
        cerr << "No se pudo crear el socket del servidor, saliento" << endl;
    }

    serverAddr_s.sin_family = AF_INET;
    serverAddr_s.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &serverAddr_s.sin_addr);

    if (bind(serverSocket_s, (sockaddr*)&serverAddr_s, sizeof(serverAddr_s)) < 0 ){
        cerr << "Can't bind to IP/port";
    }
}

void* Server::serverThread(void *clientSock_) {

    int clientSocket = *(int *) clientSock_;

    char clientIp[NI_MAXHOST];
    char server[NI_MAXSERV];
    memset(clientIp, 0, NI_MAXHOST);
    memset(server, 0, NI_MAXSERV);


    int canGetInfo = getnameinfo((sockaddr *) &clientAddr_s, sizeof(clientAddr_s),
                                 clientIp, NI_MAXHOST, server, NI_MAXSERV, 0);

    if (canGetInfo == 0) {
        cout << "El cliente " << clientIp << " se conecto al server: " << server << endl;
    } else {
        inet_ntop(AF_INET, &clientAddr_s.sin_addr, clientIp, NI_MAXHOST);
        cout << "El cliente " << clientIp << " se conecto al server(cheat): " << ntohs(clientAddr_s.sin_port) << endl;
    }

    char messageFromClient[4096];
    char messageToClient[4096];

    while(true){
        memset(messageFromClient, 0, 4096);
        int bytesReceived = recv(clientSocket, messageFromClient, 4096, 0);

        if (bytesReceived == -1) {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        else if (bytesReceived == 0) {
            cout << "Client disconnected " << endl;
            break;
        }

        cout << "Recived: " << string(messageFromClient, 0, bytesReceived) << endl;

        memset(messageToClient, 0, 4096);
        strcpy(messageToClient, "Se recibio el mensaje correctamente");

        send(clientSocket, messageToClient, strlen(messageToClient), 0 );
    }
}

void Server::Listen() {

    if(listen(serverSocket_s, 4) < 0 ) {
        cerr << "No se puede escuchar";
    }

    int clientsIter = 0;
    pthread_t clientThreads[4];

    clientSocket_s = accept(serverSocket_s, (struct sockaddr*)&clientAddr_s, &clientSize_s);

    int canCreateThread = pthread_create(&clientThreads[0], nullptr, serverThread, &clientSocket_s);
    if(canCreateThread != 0) {
        printf("Fallo al crear el thread");
    }

    pthread_join(clientThreads[0], nullptr);


//    while (clientsIter <= 3) {
//
//        clientSize_s = sizeof(clientAddr_s);
//
//        clientSocket_s = accept(serverSocket_s, (struct sockaddr*)&clientAddr_s, &clientSize_s);
//
//        if (clientSocket_s < 0){
//            cerr << "La conexion no se acepto" << endl;
//            break;
//        }
//
//        int canCreateThread = pthread_create(&clientThreads[clientsIter], nullptr, serverThread, &clientSocket_s);
//
//        if(canCreateThread != 0) {
//            printf("Fallo al crear el thread");
//            break;
//        }
//
//        clientsIter++;
//
//        for( int i = 0; i < 3; i++) pthread_join(clientThreads[i], nullptr);
//    }

}


