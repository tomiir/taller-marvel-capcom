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
#include <chrono>
#include <netinet/tcp.h>
#include <queue>
#include <csignal>
#include "../utils/Logger/Logger.h"
#include "../utils/Mapper/Mapper.h"
#include <SDL_events.h>
#include "../Json/JsonConfigs.h"
#include "../model/Game/Game.h"


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

    void setMappers(Mapper* mapperSelect_, Mapper* mapperFight_);

    static void* recvFromServer(void* arg);

    char *messageFromServerReceived();

private:

    CLogger* logger = CLogger::GetLogger();

    pthread_t clientThread;
    bool beating;

    static void brokeConnection(int num);

    void configServer(const char* serverIp, uint16_t serverPort);

    static void* sendEventToServer(void* arg);
    static void* render(void* arg);



    static void checkSendToServerError();
    static void checkRecvFromServerError();

    static void changeCurrentMapper();
};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
