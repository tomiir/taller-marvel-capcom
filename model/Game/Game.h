
#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../../controllers/ViewController/ViewController.h"

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int posX, int posY, int width, int height);
    void tick();
    void update();
    void clean();
    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ViewController* viewController;


};


#endif //TRABAJOPRACTICOTALLER_GAME_H
