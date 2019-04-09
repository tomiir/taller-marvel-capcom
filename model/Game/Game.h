
#ifndef TALLER_MARVEL_CAPCOM_GAME_H
#define TALLER_MARVEL_CAPCOM_GAME_H


#include <iostream>
#include "../../controllers/ViewController/ViewController.h"
#include "ViewControllerFactory/ViewControllerFactory.h"

class Game {

public:
    Game(int screenWidth_, int screenHeight_);
    ~Game();

    void init(const char* title, int posX, int posY);
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
    int screenWidth, screenHeight;

};


#endif //TALLER_MARVEL_CAPCOM_GAME_H
