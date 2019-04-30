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
#include <pthread.h>
#include <future>
#include <chrono>


using namespace std;


class Client {

public:
    Client() = default;
    Client(const char *ip, uint16_t port);
    ~Client() = default;
    void Connect();
    void Disconnect();
    void Send(char* message);
    char* update();
    bool isBeating();
    void hearthBeat();

private:

    pthread_t clientThread;
    bool beating;

    static void* connectClientToServer(void* arg);



};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
