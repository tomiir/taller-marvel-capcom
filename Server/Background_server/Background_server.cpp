//
// Created by arielpm on 16/05/19.
//

#include "Background_server.h"

Background_server::Background_server(string name_, int widthImage, int heightImage, int screenWidth, int screenHeight) :
        GameObject_server(name_, 0, 0, screenWidth, screenHeight){

    imgHeight = heightImage;
    imgWight = widthImage;

    CAMERA_WIDTH = screenWidth;
    CAMERA_HEIGHT = screenHeight;
    CAMERA_X_POS = (widthImage/2) - screenWidth/2;
    CAMERA_Y_POS = heightImage - screenHeight;

    camera = SDL_Rect{CAMERA_X_POS, CAMERA_Y_POS, CAMERA_WIDTH, CAMERA_HEIGHT};
}

Background_server::~Background_server() = default;

void Background_server::move(DirectionVector* moveDirection) {

    camera.x += (int) moveDirection->x;
    camera.y += (int) moveDirection->y;
    //render();  NO SE PORQUE ESTABA ACA ESTE RENDER (SOY ARI HACIENDO LA SEGUNDA PARTE DEL TP)
}


vector<int> Background_server::getCameraInfo() {

    vector<int> cameraInfo = {camera.x, camera.y, camera.w, camera.h};
    return cameraInfo;
}


vector<int> Background_server::getInfo() {

    std::vector<int> info = {imgWight, imgHeight};
    return info;
}

void Background_server::setSpeeds(int speedCam, double speedPercetageCam) {
    this->speedCam = speedCam;
    this->speedPercetageCam = speedPercetageCam;
}

int Background_server::getSpeedCam() {
    return speedCam;
}

double Background_server::getSpeedPercetageCam() {
    return speedPercetageCam;
}

vector<int> Background_server::getPosInfo() {
    vector<int> positions;
    positions[0] = camera.x;
    positions[1] = camera.y;

    return positions;
}
