
#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H


#include <iostream>
#include "../../controllers/ViewController/ViewController.h"
#include "ViewControllerFactory/ViewControllerFactory.h"

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
    ViewControllerFactory * factory; //Lo agrego para crear la primera view


};


#endif //TRABAJOPRACTICOTALLER_GAME_H
