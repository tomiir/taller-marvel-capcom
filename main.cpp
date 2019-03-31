
#include <stdio.h>
#include <string>
#include "model/Game/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* title = "Marvel vs Capcom";

int main(int argc, const char* argv[]){

       Game* game = new Game();

       game->init(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

       while(true) {
            try { game->tick(); }
            catch(int e) { break; }
       }

       game->clean();
       return 0;
}