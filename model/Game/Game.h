
#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H


#include <iostream>
#include "../../controllers/ViewController/ViewController_fight/ViewController_fight.h"
#include "ViewControllerFactory/ViewControllerFactory.h"

class Game {

public:
    Game(int screenWidth_, int screenHeight_);
    ~Game();

    void init(const char* title, int posX, int posY);
    void tick();
    void update();
    void clean();

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ViewController* viewController;
    ViewControllerFactory * factory; //Lo agrego para crear la primera ViewController
    int screenWidth, screenHeight;

};


#endif //TRABAJOPRACTICOTALLER_GAME_H
