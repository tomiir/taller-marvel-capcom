#include "Json/JsonConfigs.h"
#include <stdio.h>
#include <string>
#include "model/Game/Game.h"

#define DEBUG_LEVEL ERROR //VER COMO SACARLO DEL JSON CONFIGS

int main(int argc, const char* argv[]){

    JsonConfigs* config = JsonConfigs::getJson();

    CLogger* logger = CLogger::GetLogger();
    logger -> setLevel(DEBUG_LEVEL);
    logger ->Log("Inicializando juego", INFO, "");

    const int SCREEN_WIDTH = config->getScreenSize()[0];
    const int SCREEN_HEIGHT = config->getScreenSize()[1];

    std::string aux = config->getTitle();
    const char* title = aux.c_str();
    const int FPS = config->getFPS();


    Game* game = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);
    game->init(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    Uint32 start;

    while(true) {

        start = SDL_GetTicks();
        try { game->tick(); }
        catch(int e) { break; }

        if( (1000/FPS) > (SDL_GetTicks() - start) ){
            SDL_Delay( (1000/FPS) - (SDL_GetTicks() - start) );
        }
    }

    game->clean();
    return 0;
}