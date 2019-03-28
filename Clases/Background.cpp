//
// Created by fer on 27/03/19.
//

#include "Background.h"


Background::Background(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh, int increaseCamera) :
            GameObject(imagePath, rend, initialX, initialY, width, heigh){

                this->increaseCamera = increaseCamera;
            }

Background::~Background() = default;

void Background::moveCamera(int moveDirection) {

    if(moveDirection == 1) {

        camera.x += increaseCamera;
    }
    else if(moveDirection == -1){

            camera.x -= increaseCamera;

    }
}

void Background::render(){

    SDL_RenderCopy(renderer, objTexture, &camera, &objRect);

}