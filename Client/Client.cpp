//
// Created by fer on 27/04/19.
//

#include "Client.h"

//----SERVER VARIABLES----
int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

Client::Client(const char *ip, uint16_t port) {


    //--------- CONFIG SERVER --------------
    serverSocket_c = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr_c.sin_family = AF_INET;
    serverAddr_c.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr_c.sin_addr);
    serverSize_c = sizeof(serverAddr_c);

    beating = true;

}

void Client::Disconnect() {

    cout << "Desconectando..." << endl;
    close(serverSocket_c);
}


void Client::Connect() {

    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ) cout << "Fallo la conexion con el servidor " << endl;
}

void Client::Send(char* message) {

    if(strcmp(message, "quit") == 0) {
        beating = false;
        this->Disconnect();
        return;
    }

    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);
    if(bytesSent == -1) cerr << "Error al enviar el mensaje";

}

char* Client::update() {

    char message[4096];
    memset(message, 0, 4096);

    int bytesReceived = recv(serverSocket_c, message, 4096, 0);
    if(bytesReceived == -1){

        cout << "Error recibiendo la respuesta del server" << endl;
    }
    else{

        cout << "SERVER: " << string(message, bytesReceived) << endl;
    }
    string received = string(message, bytesReceived);
    return &received[0u]; //SI TIRA SEGSEV ES POR ESTA COSA RARA
}

/*
 * void Client::Send() {

    char message[4096];
    memset(message, 0, 4096);
    scanf("%s", message);

    if(strcmp(message, "quit") == 0) {
        beating = false;
        this->Disconnect();
        return;
    }

    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);
    if(bytesSent == -1) cerr << "Error al enviar el mensaje";

}
 */

void Client::hearthBeat(){

    char message[4096];
    future<int> scanning = async(scanf,"%s",message);
    chrono::seconds temp (10);
    char hearthbeat[1];

    while(scanning.wait_for(temp) == future_status::timeout){

        memset(hearthbeat, 0, 1);

        if(beating) Send( (char*) "1");
        else Send( (char*) "0");
    }

    Send(message);
}

bool Client::isBeating() {

    return beating;

}
