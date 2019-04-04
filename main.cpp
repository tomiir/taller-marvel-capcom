
#include <stdio.h>
#include <string>
#include "model/Game/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;

const char* title = "Marvel vs Capcom";
const int FPS = 60;

int main(int argc, const char* argv[]){

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