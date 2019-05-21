//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_BACKGROUND_SERVER_H
#define TALLER_MARVEL_CAPCOM_BACKGROUND_SERVER_H


#include "../GameObject_server/GameObject_server.h"

using namespace std;

class Background_server : public GameObject_server{

public:
    Background_server(string name_,  int width_image, int height_image, int screenWidth, int screenHeight);
    ~Background_server();

    void move(DirectionVector* moveDirection) override;
    vector<int> getCameraInfo();
    vector<int> getInfo() override;
    void setSpeeds(int speedCam,double speedPercetageCam);
    int getSpeedCam();
    double getSpeedPercetageCam();
    vector<int> getPosInfo() override ;

private:
    int speedCam;
    double speedPercetageCam;
    int CAMERA_WIDTH, CAMERA_HEIGHT, CAMERA_X_POS, CAMERA_Y_POS;

    int imgWight, imgHeight;

    SDL_Rect camera;


};


#endif //TALLER_MARVEL_CAPCOM_BACKGROUND_SERVER_H
