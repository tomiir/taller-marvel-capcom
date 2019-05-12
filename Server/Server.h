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
#include <queue>
#include "../utils/Logger/Logger.h"

#define MAXCLIENTS 2
#define PORT 54000

using namespace std;

class Server {

public:
    Server();
    ~Server() = default;
    void connect();
    static void* receivingEventsFromClient(void *clientSock_);
    static void *updateModel(void* arg);

    static void brokeConnection(int arg);

    static void *Send(void *clientSock_);

    static char * update(int clientSock);

    static void checkSendToClientError(int clientSock);
    static void checkRecvFromClientError(int clientSock);

private:
    static void clientConnected(sockaddr_in clientAddr_);
    static void* popQueue(void* arg);


};


#endif //TALLER_MARVEL_CAPCOM_SERVER_H
