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

using namespace std;

class Server {

public:
    Server();
    ~Server() = default;
    void Listen();


private:
    void* recivingClient(void* clientSocket);
    int listening, serverSock;
    struct sockaddr_in serverAddr;
};


#endif //TALLER_MARVEL_CAPCOM_SERVER_H
