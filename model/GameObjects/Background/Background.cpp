//
// Created by fer on 27/03/19.
//

#include "Background.h"

Background::Background(const char* imagePath, SDL_Renderer* rend, int widthImage, int heightImage, int screenWidth, int screenHeight) :
            GameObject(imagePath, rend, 0, 0, screenWidth, screenHeight){

                imgHeight = heightImage;
                imgWight = widthImage;

                CAMERA_WIDTH = screenWidth;
                CAMERA_HEIGH = screenHeight;
                CAMERA_X_POS = (widthImage/2) - screenWidth/2;
                CAMERA_Y_POS = heightImage - screenHeight;

                camera = SDL_Rect{CAMERA_X_POS, CAMERA_Y_POS, CAMERA_WIDTH, CAMERA_HEIGH};
            }

Background::~Background() = default;

void Background::move(std::vector<int> &moveDirection) {

    int moveDirectionX = moveDirection[0];
    int moveDirectionY = moveDirection[1];
    camera.x += moveDirectionX;
    camera.y += moveDirectionY;
    render();
}

void Background::render(){

    SDL_RenderCopy(renderer, objTexture, &camera, &objRect);
}

vector<int> Background::getCameraInfo() {
    vector<int> cameraInfo = {camera.x, camera.y, camera.w, camera.h};
    return cameraInfo;
}


vector<int> Background::getInfo() {

    std::vector<int> info = {imgWight, imgHeight};
    return info;
}