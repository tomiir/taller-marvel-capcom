//
// Created by fer on 27/04/19.
//

#include "Server.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
char buffer[1024];


Server::Server() {

    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if( serverSock == -1 ){
        cerr << "No se pudo crear el socket del servidor, saliento" << endl;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    serverSize = sizeof(serverAddr);

    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero) );

    if (bind(serverSock, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0 ){
        cerr << "Can't bind to IP/port";
    }

}

void* Server::serverThread(void *clientSock_){

    char clientMesagge[4096];

    int clientSocket = *(int*) clientSock_;

    memset(clientMesagge, 0 , 4096);

    int bytesReceived = recv( clientSocket, clientMesagge, 4096, 0);


    pthread_mutex_lock(&lock);

    if (bytesReceived == -1)
    {
        cerr << "Error in recv(). Quitting" << endl;
        pthread_mutex_unlock(&lock);
        close(clientSocket);
        pthread_exit(nullptr);
    }

    if (bytesReceived == 0)
    {
        cout << "Client disconnected " << endl;
        pthread_mutex_unlock(&lock);
        close(clientSocket);
        pthread_exit(nullptr);
    }

    cout << "el cliente: " << clientSocket << " " << string(clientMesagge, 0 , bytesReceived) << endl;

    pthread_mutex_unlock(&lock);
    sleep(1);

    cout << "exit socket" << endl;

    pthread_exit(nullptr);
}

void Server::Listen() {

    if(listen(serverSock, 4) < 0 ) {
        cerr << "No se puede escuchar";
    }

    int clientsIter = 0;
    pthread_t clientThreads[4];

    while (true) {

        clientSize = sizeof(clientAddr);
        clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, &clientSize);

        int canCreateThread = pthread_create(&clientThreads[clientsIter], NULL, serverThread, &clientSock);
        if(canCreateThread != 0) {
            printf("Fallo al crear el thread");
            break;
        }

        if( clientsIter >= 4){
            clientsIter = 0;
            while(clientsIter < 4) pthread_join( clients[clientsIter++], NULL);
            clientsIter = 0;
        }



    }

}