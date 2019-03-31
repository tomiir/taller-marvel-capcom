#ifndef TRABAJOPRACTICOTALLER_BACKGROUND_H
#define TRABAJOPRACTICOTALLER_BACKGROUND_H


#include "../GameObject/GameObject.h"


class Background : public GameObject {

public:
    Background(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh, int increaseCamera);
    ~Background();

    void moveCamera(int moveDirection);
    void render();


private:

    int increaseCamera;

    int CAMERA_WIDTH = 800;
    int CAMERA_HEIGH = 600;
    int CAMERA_X_POS = 0;
    int CAMERA_Y_POS = 0;

    SDL_Rect camera = SDL_Rect{CAMERA_X_POS, CAMERA_Y_POS, CAMERA_HEIGH, CAMERA_WIDTH};


};


#endif //TRABAJOPRACTICOTALLER_BACKGROUND_H

