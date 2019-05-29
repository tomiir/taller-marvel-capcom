
#include "Server.h"
#include "Game_server/Game_server.h"

#define MESSAGEFROMCLIENTLEN 512
#define MESSAGETOCLIENTLEN 512

//----SERVER VARIABLES----
int serverSocket_s;
struct sockaddr_in serverAddr_s;

//----CLIENT VARIABLES----

int clientSocket[MAXCLIENTS + 1];
struct sockaddr_in clientAddr[MAXCLIENTS + 1];
socklen_t clientSize[MAXCLIENTS + 1];

char messageFromClient[MESSAGEFROMCLIENTLEN];
char messageFromClient2[MESSAGEFROMCLIENTLEN];
char messageFromClient3[MESSAGEFROMCLIENTLEN];
char messageFromClient4[MESSAGEFROMCLIENTLEN];

char messageToClient[MESSAGETOCLIENTLEN];

pthread_t clientThreads[MAXCLIENTS];

queue<string> serverQueue;

bool on = true;
bool Connected11 = true;
bool Connected12 = true;
bool Connected21 = true;
bool Connected22 = true;

bool viewControllerFight = false;

Game_server* game_server;

pthread_mutex_t lock, mutex;

sig_atomic_t quitFlag = 0;



Server::Server(int cantClients_, int port_) {

    port = port_;

    CLogger* logger = CLogger::GetLogger();
    serverSocket_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket_s == -1) {
        logger->Log( "No se pudo crear el socket del servidor, saliendo..." , ERROR, strerror(errno));
    }

    serverAddr_s.sin_family = AF_INET;
    serverAddr_s.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0" , &serverAddr_s.sin_addr);

    cantClients = cantClients_;

    int option = 1;
    if (setsockopt(serverSocket_s,SOL_SOCKET,SO_REUSEADDR,&option,sizeof(int)) == -1) {
        logger -> Log("Error al setear opciones del socket, saliendo...", ERROR, strerror(errno));
        logger->closeLogger();
        exit(1);
    }

    if (bind(serverSocket_s, (sockaddr*)&serverAddr_s, sizeof(serverAddr_s)) < 0 ){
        logger->Log( "No se puede bindear al puerto o IP" , ERROR, strerror(errno));
        logger->closeLogger();
        exit(1);
    }
}


void Server::checkSendToClientError(int clientSock) {

    CLogger* logger = CLogger::GetLogger();
    switch(errno) {

        case ECONNRESET:
            logger->Log( "El cliente cerro la conexion" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case EINTR:
            logger->Log( "Una señal interrumpio el send antes de enviar el mensaje" , ERROR, strerror(errno));
            break;

        case EIO:
            logger->Log( "Hubo un problema en la red o en el transporte" , ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log( "El cliente no esta conectado" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case EPIPE:
            logger->Log( "Se recibio un SIGPIPE del cliente" , ERROR, strerror(errno));
            close(clientSock);
            logger->closeLogger();
            exit(0);
    }
}


void Server::checkRecvFromClientError(int clientSock) {

    CLogger* logger = CLogger::GetLogger();
    switch(errno) {

        case ECONNREFUSED:
            logger->Log( "El cliente rechazo la conexion" , ERROR, strerror(errno));
            close(clientSock);
            break;

        case EINTR:
            logger->Log( "Una señal interrumpio el recv antes de recibir el mensaje" , ERROR, strerror(errno));
            break;

        case ENOMEM:
            logger->Log( "No se pudo alocar memoria para el mensaje" , ERROR, strerror(errno));
            break;

        case ENOTCONN:
            logger->Log( "El cliente no esta conectado" , NETWORK, strerror(errno));
            close(clientSock);
            break;

        case ENOTSOCK:
            logger->Log( "Problema con el socket del cliente, mal configurado" , ERROR, strerror(errno));
            break;
    }
}


void *Server::Send(void *clientIter_){

    signal(SIGPIPE, SIG_IGN);

    int clientIter = *(int *) clientIter_;

    if (send(clientSocket[clientIter], messageToClient, strlen(messageToClient),0) == -1 ){
        checkSendToClientError(clientSocket[clientIter]);
    }
}


char* Server::update(int clientIter){

    if(clientIter == 0){
        memset(messageFromClient, 0, MESSAGEFROMCLIENTLEN);
        int bytesReceived = recv(clientSocket[clientIter], messageFromClient, MESSAGEFROMCLIENTLEN,0);

        if (bytesReceived == -1) {
            checkRecvFromClientError(clientSocket[clientIter]);
        }

        return messageFromClient;

    }else if(clientIter == 1){
        memset(messageFromClient2, 0, MESSAGEFROMCLIENTLEN);
        int bytesReceived = recv(clientSocket[clientIter], messageFromClient2, MESSAGEFROMCLIENTLEN,0);

        if (bytesReceived == -1) {
            checkRecvFromClientError(clientSocket[clientIter]);
        }

        return messageFromClient2;

    }else if(clientIter == 2){
        memset(messageFromClient3, 0, MESSAGEFROMCLIENTLEN);
        int bytesReceived = recv(clientSocket[clientIter], messageFromClient3, MESSAGEFROMCLIENTLEN,0);

        if (bytesReceived == -1) {
            checkRecvFromClientError(clientSocket[clientIter]);
        }

        return messageFromClient3;

    }else if(clientIter == 3){
        memset(messageFromClient4, 0, MESSAGEFROMCLIENTLEN);
        int bytesReceived = recv(clientSocket[clientIter], messageFromClient4, MESSAGEFROMCLIENTLEN,0);

        if (bytesReceived == -1) {
            checkRecvFromClientError(clientSocket[clientIter]);
        }

        return messageFromClient4;
    }


}


void* timer(void * clientIter_){

    sleep(5);

    int clientIter = *(int *) clientIter_;

    if (clientIter == 0) Connected11 = false;
    else if (clientIter == 1) Connected21 = false;
    else if (clientIter == 2 ) Connected12 = false;
    else if (clientIter == 3) Connected22 = false;

    cout << "Se desconecto: " << clientIter +1 << endl;

}


void* Server::receivingEventsFromClient(void *client_) {

    clientStruct* client = (clientStruct*) client_;

    int clientIter = client->client;
    int cantClients = client->cantClients_;


    CLogger* logger = CLogger::GetLogger();

    int speed = 60;
    Uint32 start;

    while(true){

        if (game_server->haveToChangeViewController()) {
            game_server->changeViewController();
            viewControllerFight = true;
        }

        start = SDL_GetTicks();

        pthread_t timerThread[cantClients];
        int readThread = pthread_create(&timerThread[clientIter], nullptr, timer, &clientIter);

        if(readThread !=0){
            logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
        }


        char* received = update(clientIter);

        pthread_cancel(timerThread[clientIter]);
        pthread_detach(timerThread[clientIter]);

        if (clientIter == 0) Connected11 = true;
        else if (clientIter == 1) Connected21 = true;
        else if (clientIter == 2 ) Connected12 = true;
        else if (clientIter == 3) Connected22 = true;


        if( strcmp(received, "0") == 0) {
            logger->Log( "El cliente: " + to_string(clientSocket[clientIter]) + " se desconecto" , NETWORK, "");


            if (clientIter == 0) Connected11 = false;
            else if(clientIter == 1) Connected21 = false;
            else if(clientIter == 2) Connected12 = false;
            else if (clientIter == 3) Connected22 = false;

            close(clientSocket[clientIter]);

            return nullptr;
        }


        if (viewControllerFight){

            if (cantClients == 4){
                if (((game_server->currentClientT1() == 1 and clientIter == 2) or (game_server->currentClientT1() == 3 and clientIter == 0)) and (Connected11 and Connected12)) continue;
                if (((game_server->currentClientT2() == 2 and clientIter == 3) or (game_server->currentClientT2() == 4 and clientIter == 1)) and (Connected21 and Connected22)) continue;
            }
            if (cantClients == 3){
                if (((game_server->currentClientT1() == 1 and clientIter == 2) or (game_server->currentClientT1() == 3 and clientIter == 0)) and (Connected11 and Connected12)) continue;
            }
        }


        int receivedLen = strlen(received);
        if(receivedLen != 1) {
            continue;
        }

        switch (clientIter){

            case 0:
                received[receivedLen] = '1';
                break;
            case 1:
                received[receivedLen] = '2';
                break;
            case 2:
                received[receivedLen] = '3';
                break;
            case 3:
                received[receivedLen] = '4';
                break;
            default:
                cout << "ERROR AGREGANDO CHARS PARA DISTINGUIR CLIENTES" << endl;
                break;
        }

        string recv = (string)(received);

        pthread_mutex_lock(&mutex);
        serverQueue.push(recv);
        pthread_mutex_unlock(&mutex);

        if ((1000 / speed) > (SDL_GetTicks() - start)) {
            SDL_Delay((1000 / speed) - (SDL_GetTicks() - start));
        }

    }
}


void Server::quit(int arg){
    quitFlag = 1;
}


void* Server::quit(void* cantClients_){

    char message[4096];

    while(true){
        scanf("%s", message);

        if(strcmp(message, "quit") == 0){
            quitFlag = 1;
            break;
        }
    }
}

//esta funcion se encarga de desencolar las cosas que le llegan de los clientes, actualizar el
// modelo y enviar los nuevos parametros a todos los clientes.
void* Server::updateModel(void *cantClients_){

    int cantClients = *(int *) cantClients_;

    CLogger* logger = CLogger::GetLogger();

    pthread_t quitThread;
    pthread_create(&quitThread, nullptr, quit, &cantClients);

    int client1 = 0;
    int client2 = 1;
    int client3 = 2;
    int client4 = 3;

    while(on){

        signal(SIGTERM, &quit);
        signal(SIGABRT, &quit);
        signal(SIGINT, &quit);

        if(quitFlag == 1){

            cout << "Cerrando server" << endl;

            strcpy(messageToClient, "serverDisconnect");

            while(!serverQueue.empty()){
                serverQueue.pop();
            }
            sleep(3);

            for(int i = 0; i < cantClients; i++){
                Send(&i);
                close(clientSocket[i]);
                close(serverSocket_s);
                pthread_cancel(clientThreads[i]);
            }
            return nullptr;
        }

        //En este caso cada elemneto de la cola es una serie de eventos de 5 chars cada uno(y cada elemento es de un cleinte solo)
        //Habria que evaluar cuantas veces habria que desencolar o si simplemente procesando lo de un cleinte solo a la vez serviria.
        if(serverQueue.empty()) continue;

        string event = serverQueue.front();

        //aca se realizaría todos los cambios al modelo segun las teclas que le llegaron
        game_server->handleEvent(event);

        serverQueue.pop();

        //aca se pide despues de hacer todos los cambios los parametros que se necesitan para enviarles a los clientes y que estos renderisen

        string updates = game_server->giveNewParameters();

        memset(messageToClient,0, MESSAGETOCLIENTLEN);
        strcpy(messageToClient, updates.c_str());

        int clientsIter = 0;
        pthread_t clientUpdateThreads[MAXCLIENTS];


        for(; clientsIter < cantClients; clientsIter++){

            int readThread;
            if (clientsIter == client1 and Connected11){
                readThread = pthread_create(&clientUpdateThreads[client1], nullptr, Send,
                                            &client1);
            }
            if (clientsIter == client2 and Connected21){
                readThread = pthread_create(&clientUpdateThreads[client2], nullptr, Send,
                                            &client2);
            }
            if (clientsIter == client3 and Connected12){
                readThread = pthread_create(&clientUpdateThreads[client3], nullptr, Send,
                                            &client3);
            }if (clientsIter == client4 and Connected22){
                readThread = pthread_create(&clientUpdateThreads[client4], nullptr, Send,
                                            &client4);
            }


            if(readThread != 0) {
                logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
            }
        }

        clientsIter = 0;

        for(; clientsIter < cantClients; clientsIter++){
            pthread_join(clientUpdateThreads[clientsIter], nullptr);
        }
    }

    return nullptr;
}


void Server::clientConnected(sockaddr_in clientAddr_){

    CLogger* logger = CLogger::GetLogger();
    char clientIp[NI_MAXHOST];
    char server[NI_MAXSERV];
    memset(clientIp, 0, NI_MAXHOST);
    memset(server, 0, NI_MAXSERV);

    int canGetInfo = getnameinfo((sockaddr *) &clientAddr_, sizeof(clientAddr_),
                                 clientIp, NI_MAXHOST, server, NI_MAXSERV, 0);

    if (canGetInfo == 0) {
        inet_ntop(AF_INET, &clientAddr_.sin_addr, clientIp, NI_MAXHOST);
        logger->Log( "El cliente " + string(clientIp) + " se conecto al server: " + server , NETWORK, "");
    }
}


void * Server::rejectingClients(void *clientIter_){

    int clientsIter = *(int *) clientIter_;

    while(on){

        clientSize[clientsIter] = sizeof(clientAddr[clientsIter]);
        clientSocket[clientsIter] = accept(serverSocket_s, (struct sockaddr*)&clientAddr[clientsIter], &clientSize[clientsIter]);
        clientConnected(clientAddr[clientsIter]);

        memset(messageToClient,0, MESSAGETOCLIENTLEN);
        strcpy(messageToClient, "notco");
        Send(&clientsIter);

    }
}


void Server::connect() {

    CLogger* logger = CLogger::GetLogger();

    int client1 = 0;
    int client2 = 1;
    int client3 = 2;
    int client4 = 3;


    if(listen(serverSocket_s, cantClients) < 0 ) {
        logger->Log( "No se puede escuchar", ERROR, strerror(errno));
    }

    int clientsIter = 0;

    for(; clientsIter < cantClients; clientsIter++){
        clientSize[clientsIter] = sizeof(clientAddr[clientsIter]);
        clientSocket[clientsIter] = accept(serverSocket_s, (struct sockaddr*)&clientAddr[clientsIter], &clientSize[clientsIter]);
        clientConnected(clientAddr[clientsIter]);
    }

    pthread_t extraClientsThread;

    int aux = cantClients + 1;

    int readThread = pthread_create(&extraClientsThread, nullptr, rejectingClients, &aux);
    if(readThread !=0){
        logger->Log( "Falló al crear un thread de echar clientes." , ERROR, strerror(errno));
    }


    clientsIter = 0;
    for(; clientsIter < cantClients; clientsIter++){

        memset(messageToClient,0, MESSAGETOCLIENTLEN);
        if (clientsIter == client1){
            strcpy(messageToClient, "team1");
            Send(&client1);
        }
        if (clientsIter == client2){
            strcpy(messageToClient, "team2");
            Send(&client2);
        }
        if (clientsIter == client3){
            strcpy(messageToClient, "team1");
            Send(&client3);
        }
        if (clientsIter == client4){
            strcpy(messageToClient, "team2");
            Send(&client4);
        }
    }

    clientsIter = 0;

    for(; clientsIter < cantClients; clientsIter++){
        memset(messageToClient,0, MESSAGETOCLIENTLEN);
        if (clientsIter == client1){
            strcpy(messageToClient, "cnect");
            Send(&client1);
        }
        if (clientsIter == client2){
            strcpy(messageToClient, "cnect");
            Send(&client2);
        }
        if (clientsIter == client3){
            strcpy(messageToClient, "cnect");
            Send(&client3);
        }
        if (clientsIter == client4){
            strcpy(messageToClient, "cnect");
            Send(&client4);
        }
    }


    logger->Log( "Ya se conectaron los clientes" , INFO, "");


    logger->Log("Inicializando juego", INFO, "");
    JsonConfigs *config = JsonConfigs::getJson();

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    game_server = new Game_server(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_server->init();

    //Se arranca a enviar el conectado y el team a los clientes


    pthread_mutex_init(&lock,NULL);

    clientsIter = 0;


    clientStruct C1 = {cantClients, 0};
    clientStruct C2 = {cantClients, 1};
    clientStruct C3 = {cantClients, 2};
    clientStruct C4 = {cantClients, 3};


    for(; clientsIter < cantClients; clientsIter++){
        int readThread;
        if (clientsIter == client1){

            readThread = pthread_create(&clientThreads[client1], nullptr, receivingEventsFromClient,
                                        &C1);
        }
        if (clientsIter == client2){
            readThread = pthread_create(&clientThreads[client2], nullptr, receivingEventsFromClient,
                                        &C2);
        }
        if (clientsIter == client3){
            readThread = pthread_create(&clientThreads[client3], nullptr, receivingEventsFromClient,
                                        &C3);
        }if (clientsIter == client4){
            readThread = pthread_create(&clientThreads[client4], nullptr, receivingEventsFromClient,
                                        &C4);
        }

        if(readThread != 0) {
            logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
        }
    }


    pthread_t updateModelThread;

    readThread = pthread_create(&updateModelThread, nullptr, updateModel, &cantClients);
    if(readThread !=0){
        logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
    }

    clientsIter = 0;

    for(; clientsIter < cantClients; clientsIter++){
        pthread_join(clientThreads[clientsIter], nullptr);
    }

    //aca lo cancelo porque si se fueron los clientes ya que joinearon todos los hilos no tendria que seguir updateando el modelo
    pthread_cancel(updateModelThread);
    pthread_cancel(extraClientsThread);

    pthread_detach(updateModelThread);
    pthread_detach(extraClientsThread);

    pthread_mutex_destroy(&lock);
    on = false;

    logger->Log( "Se desconectaron todos los clientes, saliendo del juego." , INFO, "");
    logger->closeLogger();
    close(serverSocket_s);

}





