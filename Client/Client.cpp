//
// Created by fer on 27/04/19.
//

#include <csignal>
#include "Client.h"

//----SERVER VARIABLES----
int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

Client::Client(const char *ip, uint16_t port) {


    //--------- CONFIG SERVER --------------
    serverSocket_c = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    serverAddr_c.sin_family = AF_INET;
    serverAddr_c.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serverAddr_c.sin_addr);
    serverSize_c = sizeof(serverAddr_c);
    beating = true;

}

void Client::Disconnect() {

    Send( (char*) "0");
    cout << "Desconectando..." << endl;
    close(serverSocket_c);
}


bool Client::Connect() {

    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ){
        cout << "Fallo la conexion con el servidor " << endl;
        close(serverSocket_c);
        return false;
    }
    return true;

}

void Client::Send(char* message) {

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

sig_atomic_t term_client = 0;

void Client::handler(int num){
    term_client = 1;
}


void Client::hearthBeat(){

    signal(SIGINT, handler);
    signal(SIGQUIT, handler);

    char message[4096];
    future<int> scanning = async(scanf,"%s",message);
    chrono::milliseconds temp (1500);

    char hearthbeat[1];

    while(scanning.wait_for(temp) == future_status::timeout){

        signal(SIGPIPE, SIG_IGN);

        int error_code;
        socklen_t error_code_size = sizeof(error_code);
        getsockopt(serverSocket_c, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);

        if(error_code){
            cout << "el server se desconecto" << endl;
            close(serverSocket_c);
            exit(0);
        }

        if(term_client){
            beating = false;
            this->Disconnect();
            exit(0);
        }

        memset(hearthbeat, 0, 1);
        Send((char *) "1");
    }

    if(strcmp(message, "quit") == 0) {
        beating = false;
        this->Disconnect();
        return;
    }

    Send(message);
}

bool Client::isBeating() {

    return beating;
}