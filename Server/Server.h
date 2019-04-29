//
// Created by fer on 27/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SERVER_H
#define TALLER_MARVEL_CAPCOM_SERVER_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <pthread.h>
#include <sys/time.h>

using namespace std;

class Server {

public:
    Server();
    ~Server() = default;
    void Listen();
    static void* serverThread(void *clientSock_);


private:

    int serverSock, clientSock;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage clientAddr;
    socklen_t clientSize;
    int clients[4];

    socklen_t serverSize;
};


#endif //TALLER_MARVEL_CAPCOM_SERVER_H
