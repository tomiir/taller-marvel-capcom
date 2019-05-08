#include "Json/JsonConfigs.h"
#include <stdio.h>
#include <string>
#include "model/Game/Game.h"
#include "Server/Server.h"
#include "Client/Client.h"

#define DEBUG_LEVEL DEBUG //VER COMO SACARLO DEL JSON CONFIGS

int main(int argc, const char* argv[]){


    CLogger *logger = CLogger::GetLogger();
    logger->Log("Inicializando juego", INFO, "");
    JsonConfigs *config = JsonConfigs::getJson();

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    Game *game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

    std::string aux = config->getTitle();
    const char *title = aux.c_str();

    game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    int modo = 1;
    logger->setLevel(DEBUG_LEVEL);

    if(modo == 1) {

        if (argc < 2 and argc > 4) {
            logger->Log("Falta el modo de inicializacion de la aplicacion serverAddr o cliente\n", ERROR, "");
            logger ->closeLogger();
            exit(1);
        }

        if (argc == 2 and string(argv[1]) == "server") {
            logger->Log("------------------------Logger del server --------------------------", DEBUG, "");
            logger ->Log("Escuchando con el server", INFO, "");
            Server *server = new Server();
            server->connect();

        } else if (argc == 4 and string(argv[1]) == "client") {
            //chequear si es una ip
            logger->Log("------------------------Logger del cliente --------------------------", DEBUG, "");



            const char *ip = argv[2];
            int port = atoi(argv[3]);

            Client *client = new Client(ip, port);
            bool connected = client->Connect();
            if (!connected) return -1;

            if(strcmp(client->update(), "team1-1") == 0 or strcmp(client->update(), "team2-1") == 0){
                client->setMappers(new EventToValueMapper_charSelect_1, new EventToValueMapper_player1 );
            }
            else if(strcmp(client->update(), "team1-2") == 0 or strcmp(client->update(), "team2-2") == 0 ){
                client->setMappers(new EventToValueMapper_charSelect_2, new EventToValueMapper_player2 );
            }
            else{
                cout << "Error al setear los mappers" << endl;
                exit(0);
            }

            if (strcmp(client->update(), "connected") == 0) {
                logger->Log( "Conectado al servidor", INFO, "");
                client->Initialice();
            }

        } else {
            logger->Log( "error al mandar el parametro mode", ERROR, "");
        }
    }

    else {

        logger->Log("Inicializando juego", INFO, "");
        JsonConfigs *config = JsonConfigs::getJson();

        const int SCREEN_WIDTH = config->getScreenSize()[0];
        const int SCREEN_HEIGHT = config->getScreenSize()[1];

        std::string aux = config->getTitle();
        const char *title = aux.c_str();
        const int FPS = config->getFPS();

        Game *game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
        game->init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        Uint32 start;

        while (true) {
            start = SDL_GetTicks();
            try { game->tick(); }
            catch (int e) { break; }

            if ((1000 / FPS) > (SDL_GetTicks() - start)) {
                SDL_Delay((1000 / FPS) - (SDL_GetTicks() - start));
            }
        }

        game->clean();
        return 0;
    }
}