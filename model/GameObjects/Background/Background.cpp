//
// Created by fer on 27/03/19.
//

#include "Background.h"

int RIGHT = 1;
int LEFT = -1;

Background::Background(const char* imagePath, SDL_Renderer* rend, int initialX, int initialY, int width, int heigh, int increaseCamera) :
            GameObject(imagePath, rend, initialX, initialY, width, heigh){

                this->increaseCamera = increaseCamera;
            }

Background::~Background() = default;

void Background::move(std::vector<int> &moveDirection) {
    int moveDirectionX = moveDirection[0];
    camera.x += moveDirectionX;
    camera = SDL_Rect{ camera.x, 0, CAMERA_WIDTH, CAMERA_HEIGH};
    render();
}

void Background::render(){

    SDL_RenderCopy(renderer, objTexture, &camera, &objRect);

}