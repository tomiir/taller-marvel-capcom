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
#include "../Json/JsonConfigs.h"
#include <csignal>
#include <unistd.h>


#define MAXCLIENTS 4

using namespace std;

typedef struct {
    int cantClients_;
    int client;
} clientStruct;

class Server {

public:
    Server(int cantClients_, int port_);
    ~Server() = default;
    void connect(const char* mode);
    static void* receivingEventsFromClient(void *clientSock_);
    static void *updateModel(void* arg);

    static void *Send(void *clientSock_);

    static char * update(int clientSock);

    static void checkSendToClientError(int clientSock);
    static void checkRecvFromClientError(int clientSock);

    static void *rejectingClients(void *clientIter_);

private:
    static void clientConnected(sockaddr_in clientAddr_);
    static void* quit(void* arg);
    static void quit(int arg);
    int cantClients;
    int port;

};


#endif //TALLER_MARVEL_CAPCOM_SERVER_H
