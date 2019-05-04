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
#include <netinet/tcp.h>

using namespace std;


class Client {

public:
    Client() = default;
    Client(const char* serverIp, uint16_t serverPort);
    ~Client() = default;
    bool Connect();
    void Disconnect();
    void Send(char* message);
    char* update();
    bool isBeating();
    void hearthBeat();

private:


    pthread_t clientThread;
    bool beating;

    static void brokeConnection(int num);

    void configServer(const char* serverIp, uint16_t serverPort);

    bool enable_keepalive();

    void checkSendToServerError();
};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
