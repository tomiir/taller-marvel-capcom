//
// Created by fer on 27/04/19.
//

#include "Client.h"



Client::Client(const char *ip, int port) {

    clientSize = sizeof(clientAddr);
    serverSize = sizeof(serverAddr);

    serverSock = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);

}

void Client::Disconnect() {

}

void Client::Connect() {

    int connection = connect(serverSock, (struct sockaddr*) &serverAddr, serverSize);
    if(!connection){
        cout << "Fallo la conexion con el servidor " << endl;
    }
}

void Client::send() {

}

void Client::update() {

}

void Client::hearthBeat() {

}
