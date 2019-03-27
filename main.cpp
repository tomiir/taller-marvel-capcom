
#include <stdio.h>
#include <string>
#include "Clases/Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* title = "Marvel vs Capcom";

Game* game = nullptr;

int main(int argc, const char* argv[])
{
       game = new Game();

       game->init(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);

       while(game->running())
       {
            game->handleEvents();
            game->update();
            game->render();
       }

       game->clean();
       return 0;
}