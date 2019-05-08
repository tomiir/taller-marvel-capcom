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
#include <queue>
#include "../utils/Logger/Logger.h"
#include "../utils/EventToValueMapper/EventToValueMapper_player/EventToValueMapper.h"
#include "../utils/EventToValueMapper/EventToValueMapper_charSelect/EventToValueMapper_charSelect.h"

using namespace std;


class Client {

public:
    Client() = default;

    Client(const char *serverIp, uint16_t serverPort);

    ~Client() = default;

    bool Connect();

    void Disconnect();

    void Send(char *message);

    bool isBeating();

    void hearthBeat();

    void Initialice();

    void setMappers(EventToValueMapper_charSelect* mapperSelect_, EventToValueMapper* mapperFight_);

private:

    CLogger* logger = CLogger::GetLogger();

    pthread_t clientThread;
    bool beating;

    static void brokeConnection(int num);

    void configServer(const char* serverIp, uint16_t serverPort);

    static void* sendEventToServer(void* arg);
    static void* recvFromServer(void* arg);
    static void* render(void* arg);



    static void checkSendToServerError();
    static void checkRecvFromServerError();
};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
