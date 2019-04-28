#include "Json/JsonConfigs.h"
#include <stdio.h>
#include <string>
#include "model/Game/Game.h"
#include "Server/Server.h"
#include "Client/Client.h"

#define DEBUG_LEVEL DEBUG

int main(int argc, const char* argv[]){

    if(argc < 2 and argc > 4) {
        cout << "Falta el modo de inicializacion de la aplicacion serverAddr o cliente\n" << endl;
        exit(1);
    }

    if( argc == 2 and string(argv[1]) == "server"){
        Server* server = new Server();
        server->Listen();

    }
    else if( argc == 4 and string(argv[1]) == "client"){
        //chequear si es una ip
        const char* ip = argv[2];
        int port = atoi(argv[3]);
        Client* client = new Client(ip, port);

    }
    else{
        cout << "error al mandar el parametro mode" << endl;
    }


//        CLogger* logger = CLogger::GetLogger();
//        logger -> setLevel(DEBUG_LEVEL);
//        logger ->Log("Inicializando juego", INFO, "");
//
//        JsonConfigs* config = JsonConfigs::getJson();
//
//
//
//        const int SCREEN_WIDTH = config->getScreenSize()[0];
//        const int SCREEN_HEIGHT = config->getScreenSize()[1];
//
//        std::string aux = config->getTitle();
//
//        const char* title = aux.c_str();
//
//        const int FPS = config->getFPS();
//
//
//       Game* game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
//
//       game->init(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
//
//       Uint32 start;
//
//       while(true) {
//           start = SDL_GetTicks();
//            try { game->tick(); }
//            catch(int e) { break; }
//
//            if( (1000/FPS) > (SDL_GetTicks() - start) ){
//                SDL_Delay( (1000/FPS) - (SDL_GetTicks() - start) );
//            }
//       }
//
//       game->clean();
//       return 0;
}