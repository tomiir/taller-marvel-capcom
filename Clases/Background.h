#ifndef TRABAJOPRACTICOTALLER_BACKGROUND_H
#define TRABAJOPRACTICOTALLER_BACKGROUND_H


#include "GameObject.h"

class Background : public GameObject {

public:
    Background(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh, int increaseCamera);
    ~Background();

    void moveCamera(int moveDirection);
    void render();


private:

    int increaseCamera;
    SDL_Rect camera = SDL_Rect{0,0,600,800};


};


#endif //TRABAJOPRACTICOTALLER_BACKGROUND_H

