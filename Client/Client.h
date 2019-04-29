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
    Client(const char *ip, uint16_t port);
    ~Client() = default;
    void Connect();
    void Disconnect();
    void Send();
    void update();
    void hearthBeat();

private:

    struct sockaddr_in clientAddr;

    socklen_t clientSize;

    static void* clientThread(void* arg);



};


#endif //TALLER_MARVEL_CAPCOM_CLIENT_H
