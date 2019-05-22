
#include "Server.h"
#include "Game_server/Game_server.h"

#define MESSAGEFROMCLIENTLEN 512
#define MESSAGETOCLIENTLEN 512

//----SERVER VARIABLES----
int serverSocket_s;
struct sockaddr_in serverAddr_s;
socklen_t serverSize_s;

//----CLIENT VARIABLES----

int clientSocket[MAXCLIENTS + 1];
struct sockaddr_in clientAddr[MAXCLIENTS + 1];
socklen_t clientSize[MAXCLIENTS + 1];

char messageFromClient[MESSAGEFROMCLIENTLEN];
char messageFromClient2[MESSAGEFROMCLIENTLEN];
char messageFromClient3[MESSAGEFROMCLIENTLEN];
char messageFromClient4[MESSAGEFROMCLIENTLEN];

char messageToClient[MESSAGETOCLIENTLEN];


queue<string> serverQueue;

bool on = true;
bool Connected11 = true;
bool Connected12 = true;
bool Connected21 = true;
bool Connected22 = true;

bool viewControllerFight = false;

Game_server* game_server;

pthread_mutex_t lock;

pthread_mutex_t mutex;



Server::Server() {

    CLogger* logger = CLogger::GetLogger();
    serverSocket_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket_s == -1) {
        logger->Log( "No se pudo crear el socket del servidor, saliendo..." , ERROR, strerror(errno));
    }

    serverAddr_s.sin_family = AF_INET;
    serverAddr_s.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0" , &serverAddr_s.sin_addr);

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

sig_atomic_t serverBrokeConnection = 0;




void Server::brokeConnection(int arg){
    serverBrokeConnection = 1;
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


//void * timer(void * clientIter_){
//
//    int clientIter = *(int *) clientIter_;
//
//    sleep(3);
//
//    if (clientIter == 0) Connected11 = false;
//    else if (clientIter == 1) Connected21 = false;
//    else if (clientIter == 2 ) Connected12 = false;
//    else Connected22 = false;
//
//}




void* Server::receivingEventsFromClient(void *clientIter_) {

    int clientIter = *(int *) clientIter_;


    CLogger* logger = CLogger::GetLogger();

    int speed = 60;
    Uint32 start;

//    pthread_t timerThread;
//
//    int readThread = pthread_create(&timerThread, nullptr, timer, &clientIter);
//    if(readThread !=0){
//        logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
//    }

    while(true){

        if (game_server->haveToChangeViewController()) {
            game_server->changeViewController();
            viewControllerFight = true;
        }

        start = SDL_GetTicks();
//
//        signal(SIGINT, brokeConnection);
//        signal(SIGTSTP, brokeConnection);
//        signal(SIGQUIT, brokeConnection);


//        if(serverBrokeConnection == 1){
//
//            memset(messageToClient,0, MESSAGETOCLIENTLEN);
//            strcpy(messageToClient, "El servidor se desconecto");
//            Send(&clientIter);
//            close(serverSocket_s);
//            return nullptr;
//        }
        //Aca habria que analizar lo de si no recibe por un tiempo nada darlo por muerto(seria el heartbeat)
        //


        char* received = update(clientIter);

//        if (clientIter == 0) Connected11 = true;
//        else if (clientIter == 1) Connected21 = true;
//        else if (clientIter == 2 ) Connected12 = true;
//        else Connected22 = true;

//        pthread_kill(timerThread, SIGCONT);


        if( strcmp(received, "0") == 0) {
            logger->Log( "El cliente: " + to_string(clientSocket[clientIter]) + " se desconecto" , NETWORK, "");
            close(clientSocket[clientIter]);

            if (clientIter == 0) Connected11 = false;
            else if(clientIter == 1) Connected21 = false;
            else if(clientIter == 2) Connected12 = false;
            else Connected22 = false;


            return nullptr;
        }

        //        ESTA ES LA LOGICA QUE SE ME OCURRIO PARA NO ENCOLAR LOS MENSAJES DE LOS CLEINTES QUE NO ESTAN JUGANDO.
//        HAY QUE PROBARLO CON MAS COMPUS PORQUE LA MIA CASI MUERE CON CUATRO CLIENTES xD.
        if (viewControllerFight){
            if (MAXCLIENTS == 4){
                if (((game_server->currentClientT1() == 1 and clientIter == 2) or (game_server->currentClientT1() == 3 and clientIter == 0)) and (Connected11 and Connected12)) continue;
                if (((game_server->currentClientT2() == 2 and clientIter == 3) or (game_server->currentClientT2() == 4 and clientIter == 1)) and (Connected21 and Connected22)) continue;
            }
            if (MAXCLIENTS == 3){
                if (((game_server->currentClientT1() == 1 and clientIter == 2) or (game_server->currentClientT1() == 3 and clientIter == 0)) and (Connected11 and Connected12)) continue;
            }
        }

        int aux = strlen(received);
        if(aux != 5) continue;

        switch (clientIter){

            case 0:
                received[aux] = '0';
                received[aux + 1] = '0';
                break;
            case 1:
                received[aux] = '0';
                received[aux + 1] = '1';
                break;
            case 2:
                received[aux] = '1';
                received[aux + 1] = '0';
                break;
            case 3:
                received[aux] = '1';
                received[aux + 1] = '1';
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






//esta funcion se encarga de desencolar las cosas que le llegan de los clientes, actualizar el
// modelo y enviar los nuevos parametros a todos los clientes.
void* Server::updateModel(void *arg){

    CLogger* logger = CLogger::GetLogger();

    int speed = 60;
    Uint32 start;

    int client1 = 0;
    int client2 = 1;
    int client3 = 2;
    int client4 = 3;

    while(on){

        start = SDL_GetTicks();

        //En este caso cada elemneto de la cola es una serie de eventos de 5 chars cada uno(y cada elemento es de un cleinte solo)
        //Habria que evaluar cauntas veces habria que desencolar o si simplemente procesando lo de un cleinte solo a la vez serviria.
        if(serverQueue.empty()) continue;

        string event = serverQueue.front();

        //aca se realizaría todos los cambios al modelo segun las teclas que le llegaron
        game_server->handleEvent(event);

        serverQueue.pop();

        //aca se pide despues de hacer todos los cambios los parametros que se necesitan para enviarles a los clientes y que estos renderisen

        string updates = game_server->giveNewParameters();

        //cout << updates << endl;

        memset(messageToClient,0, MESSAGETOCLIENTLEN);
        strcpy(messageToClient, updates.c_str());

        int clientsIter = 0;
        pthread_t clientUpdateThreads[MAXCLIENTS];


        for(; clientsIter < MAXCLIENTS; clientsIter++){

            int readThread;
            if (clientsIter == client1){
                readThread = pthread_create(&clientUpdateThreads[client1], nullptr, Send,
                                            &client1);
            }
            if (clientsIter == client2){
                readThread = pthread_create(&clientUpdateThreads[client2], nullptr, Send,
                                            &client2);
            }
            if (clientsIter == client3){
                readThread = pthread_create(&clientUpdateThreads[client3], nullptr, Send,
                                            &client3);
            }if (clientsIter == client4){
                readThread = pthread_create(&clientUpdateThreads[client4], nullptr, Send,
                                            &client4);
            }


            if(readThread != 0) {
                logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
            }
        }

        clientsIter = 0;

        for(; clientsIter < MAXCLIENTS; clientsIter++){
            pthread_join(clientUpdateThreads[clientsIter], nullptr);
        }

//        if ((1000 / speed) > (SDL_GetTicks() - start)) {
//            SDL_Delay((1000 / speed) - (SDL_GetTicks() - start));
//        }

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


    if(listen(serverSocket_s, MAXCLIENTS) < 0 ) {
        logger->Log( "No se puede escuchar", ERROR, strerror(errno));
    }

    int clientsIter = 0;
    pthread_t clientThreads[MAXCLIENTS];

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        clientSize[clientsIter] = sizeof(clientAddr[clientsIter]);
        clientSocket[clientsIter] = accept(serverSocket_s, (struct sockaddr*)&clientAddr[clientsIter], &clientSize[clientsIter]);
        clientConnected(clientAddr[clientsIter]);
    }

    pthread_t extraClientsThread;

    int aux = MAXCLIENTS + 1;

    int readThread = pthread_create(&extraClientsThread, nullptr, rejectingClients, &aux);
    if(readThread !=0){
        logger->Log( "Falló al crear un thread de echar clientes." , ERROR, strerror(errno));
    }


    clientsIter = 0;
    for(; clientsIter < MAXCLIENTS; clientsIter++){

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

    for(; clientsIter < MAXCLIENTS; clientsIter++){
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


    //ACA SE DEBERIA INICIALIZAR TODOO EL MODELO

    logger->Log("Inicializando juego", INFO, "");
    JsonConfigs *config = JsonConfigs::getJson();

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    game_server = new Game_server(SCREEN_WIDTH, SCREEN_HEIGHT);
    game_server->init();

    //Se arranca a enviar el conectado y el team a los clientes


    pthread_mutex_init(&lock,NULL);

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        int readThread;
        if (clientsIter == client1){
            readThread = pthread_create(&clientThreads[client1], nullptr, receivingEventsFromClient,
                                            &client1);
        }
        if (clientsIter == client2){
            readThread = pthread_create(&clientThreads[client2], nullptr, receivingEventsFromClient,
                                        &client2);
        }
        if (clientsIter == client3){
            readThread = pthread_create(&clientThreads[client3], nullptr, receivingEventsFromClient,
                                        &client3);
        }if (clientsIter == client4){
            readThread = pthread_create(&clientThreads[client4], nullptr, receivingEventsFromClient,
                                        &client4);
        }



        if(readThread != 0) {
            logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
        }
    }


    pthread_t updateModelThread;

    readThread = pthread_create(&updateModelThread, nullptr, updateModel, nullptr);
    if(readThread !=0){
        logger->Log( "Falló al crear un thread, saliendo del juego." , ERROR, strerror(errno));
    }

    clientsIter = 0;

    for(; clientsIter < MAXCLIENTS; clientsIter++){
        pthread_join(clientThreads[clientsIter], nullptr);
    }

    //aca lo cancelo porque si se fueron los clientes ya que joinearon todos los hilos no tendria que seguir updateando el modelo
    pthread_cancel(updateModelThread);
    pthread_cancel(extraClientsThread);
    pthread_mutex_destroy(&lock);
//    pthread_mutex_destroy(&mutex);
    on = false;

    logger->Log( "Se desconectaron todos los clientes, saliendo del juego." , INFO, "");
    logger->closeLogger();
    close(serverSocket_s);

}





