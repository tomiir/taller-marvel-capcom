//
// Created by fer on 27/04/19.
//

#include "Client.h"

//----SERVER VARIABLES----
int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

//----CLIENT VARIABLES----
struct sockaddr_in clientAddr_c;
socklen_t clientSize_c;
int clientSocket_c;




Client::Client(const char *ip, uint16_t port) {


    //--------- CONFIG SERVER --------------
    serverSocket_c = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr_c.sin_family = AF_INET;
    serverAddr_c.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr_c.sin_addr);
    serverSize_c = sizeof(serverAddr_c);

//    if( bind(serverSocket_c, (sockaddr*)&serverAddr_c, serverSize_c ) < 0){
//        cerr << "problem to bind server" << endl;
//        this->Disconnect();
//    }

    //--------- CONFIG CLIENT --------------
    clientSocket_c = socket(PF_INET, SOCK_STREAM, 0);

    hearthBeat = true;

}

void Client::Disconnect() {

    cout << "Desconectando..." << endl;
    close(serverSocket_c);
    pthread_exit(nullptr);
}

void* Client::connectClientToServer(void* arg) {

    int connection = connect(clientSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ) cout << "Fallo la conexion con el servidor " << endl;

}

void Client::Connect() {

    int canCreateThread = pthread_create(&clientThread, nullptr, connectClientToServer, nullptr);
    if(canCreateThread != 0) printf("Fallo al crear el thread");
}

void Client::Send() {

    char message[4096];
    memset(message, 0, 4096);
    scanf("%s", message);

    if(strcmp(message, "quit") == 0) {
        hearthBeat = false;
        this->Disconnect();
    }

    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);
    if(bytesSent == -1) cerr << "Error al enviar el mensaje";

}

void Client::update() {

}

bool Client::isBeating() {

    return hearthBeat;

}
