//
// Created by fer on 27/04/19.
//

#include "Client.h"

int serverSock = 0;
struct sockaddr_in serverAddr;
socklen_t serverSize;
char message[4096];


Client::Client(const char *ip, uint16_t port) {


    clientSize = sizeof(clientAddr);
    serverSize = sizeof(serverAddr);

    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);
    memset(serverAddr.sin_zero, 0, sizeof(serverAddr.sin_zero) );

}

void Client::Disconnect() {

    close(serverSock);
}

void* Client::clientThread(void* arg) {

    char buffer[1024];

    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    int connection = connect(clientSocket, (struct sockaddr*) &serverAddr, serverSize);
    if(connection < 0 ) cout << "Fallo la conexion con el servidor " << endl;



    strcpy(message, "que onda perro");
    send(clientSocket, message, strlen(message), 0);

    pthread_exit(nullptr);

}

void Client::Connect() {

    pthread_t thread;
    int canCreateThread = pthread_create(&thread, nullptr, clientThread, nullptr);
    if(canCreateThread != 0) printf("Fallo al crear el thread");

}

void Client::Send() {

}

void Client::update() {

}

void Client::hearthBeat() {

}
