//
// Created by fer on 27/03/19.
//

#include "Background.h"

Background::Background(const char* imagePath, string name_, int z_index, SDL_Renderer* rend, int widthImage, int heightImage, int screenWidth, int screenHeight) :
            GameObject(imagePath,name_, z_index, rend, 0, 0, screenWidth, screenHeight){

                imgHeight = heightImage;
                imgWight = widthImage;

                CAMERA_WIDTH = screenWidth;
                CAMERA_HEIGHT = screenHeight;
                CAMERA_X_POS = (widthImage/2) - screenWidth/2;
                CAMERA_Y_POS = heightImage - screenHeight;

                camera = SDL_Rect{CAMERA_X_POS, CAMERA_Y_POS, CAMERA_WIDTH, CAMERA_HEIGHT};
            }

//Background::~Background() = default;

void Background::move(DirectionVector* moveDirection) {

    camera.x += (int) moveDirection->x;
    camera.y += (int) moveDirection->y;
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

void Background::setSpeeds(int speedCam, double speedPercetageCam) {
    this->speedCam = speedCam;
    this->speedPercetageCam = speedPercetageCam;
}

int Background::getSpeedCam() {
    return speedCam;
}

double Background::getSpeedPercetageCam() {
    return speedPercetageCam;
}
