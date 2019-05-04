//
// Created by fer on 27/04/19.
//

#include <csignal>
#include "Client.h"
#define NOBEAT (char*)"0"
#define BEAT (char*)"1"

//----SERVER VARIABLES----
int serverSocket_c;
struct sockaddr_in serverAddr_c;
socklen_t  serverSize_c;

char messageFromServer[4096];
char messageToSever[4096];
char messageFromInput[4096];




void Client::configServer(const char* serverIp, uint16_t serverPort){

    serverSocket_c = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    serverAddr_c.sin_family = AF_INET;
    serverAddr_c.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIp, &serverAddr_c.sin_addr);
    serverSize_c = sizeof(serverAddr_c);
}


Client::Client(const char* serverIp, uint16_t serverPort) {

    configServer(serverIp, serverPort);
    beating = true;
}

void Client::Disconnect() {

    Send( NOBEAT );
    cout << "Desconectando..." << endl;
    close(serverSocket_c);
}


bool Client::Connect() {

    int connection = connect(serverSocket_c, (struct sockaddr*) &serverAddr_c, serverSize_c);
    if(connection < 0 ){
        cout << "Fallo la conexion con el servidor " << endl;
        return false;
    }
    cout << "Conectando con el servidor..." << endl;
    return true;
}


void Client::checkRecvFromServerError(){

    switch(errno) {

        case ECONNREFUSED:
            cout << "El server rechazo la conexion" << endl;
            close(serverSocket_c);
            break;
        case EINTR:
            cout << "Una señal interrumpio el recv antes de recibir el mensaje" << endl;
            break;
        case ENOMEM:
            cout << "No se pudo alocar memoria para el mensaje" << endl;
            break;
        case ENOTCONN:
            cout << "El server no esta conectado" << endl;
            close(serverSocket_c);
            break;
        case ENOTSOCK:
            cout << "Problema con el socket del server, mal configurado" << endl;
            break;
    }
}
void Client::checkSendToServerError(){

    switch(errno) {

        case ECONNRESET:
            cout << "El server cerro la conexion" << endl;
            close(serverSocket_c);
            break;
        case EINTR:
            cout << "Una señal interrumpio el send antes de enviar el mensaje" << endl;
            break;
        case EIO:
            cout << "Hubo un problema en la red o en el transporte" << endl;
            break;
        case ENOTCONN:
            cout << "El server no esta conectado" << endl;
            close(serverSocket_c);
            break;
        case EPIPE:
            cout << "Se recibio un SIGPIPE del server" << endl;
            close(serverSocket_c);
            //aca tendria que seguir intentando reconectarse al server
            exit(0);
    }
}

void Client::Send(char* message) {


    ssize_t bytesSent = send(serverSocket_c, message, strlen(message), 0);

    if(bytesSent == -1){
        checkSendToServerError();
    }

}

char* Client::update() {

    memset(messageFromServer, 0, 4096);
    int bytesReceived = recv(serverSocket_c, messageFromServer, 4096, 0);

    if(bytesReceived == -1){
        checkRecvFromServerError();
    }

    string messageReceived = string(messageFromServer, bytesReceived);
    cout << "SERVER: " << messageReceived << endl;
    return &messageReceived[0u]; //SI TIRA SEGSEV ES POR ESTA COSA RARA
}

sig_atomic_t clientBrokeConnection = 0;

void Client::brokeConnection(int arg){
    clientBrokeConnection = 1;
}


void Client::hearthBeat(){

    signal(SIGINT, brokeConnection);
    signal(SIGQUIT, brokeConnection);
    signal(SIGTSTP, brokeConnection);
    signal(SIGPIPE, SIG_IGN);


    memset(messageFromInput, 0, 4096);
    future<int> scanning = async(scanf,"%s",messageFromInput);
    chrono::milliseconds waitTime (2000);

    while(scanning.wait_for(waitTime) == future_status::timeout){

        if(clientBrokeConnection){
            beating = false;
            this->Disconnect();
            exit(0);
        }
        Send(BEAT);
    }

    if(strcmp(messageFromInput, "quit") == 0) {
        beating = false;
        this->Disconnect();
        return;
    }

    Send(messageFromInput);
}

bool Client::isBeating() {

    return beating;
}