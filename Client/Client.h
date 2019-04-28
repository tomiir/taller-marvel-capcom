//
// Created by fer on 27/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CLIENT_H
#define TALLER_MARVEL_CAPCOM_CLIENT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;


class Client {

public:
    Client() = default;
    Client(const char *ip, int port);
    ~Client() = default;
    void Connect();
    void Disconnect();
    void send();
    void update();
    void hearthBeat();

private:

    int serverSock = 0;
    int clientSock = 0;

    struct sockaddr_in clientAddr;
    struct sockaddr_in serverAddr;

    socklen_t clientSize;
    socklen_t serverSize;



};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
