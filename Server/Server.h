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

    //Despeus va a tener que ser del tipo viewController y cambiar cuando tnega que pasar a figth
    //Al usarlo en una funcion estatica me obligo a que sea estatico

    static void changeView();
};


#endif //TALLER_MARVEL_CAPCOM_SERVER_H
