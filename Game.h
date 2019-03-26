//
// Created by fer on 25/03/19.
//

#ifndef TRABAJOPRACTICOTALLER_GAME_H
#define TRABAJOPRACTICOTALLER_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {

public:
    Game();
    ~Game();

    void init(const char* title, int posX, int posY, int width, int height);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

};


#endif //TRABAJOPRACTICOTALLER_GAME_H
