//
// Created by fer on 27/03/19.
//

#include "Background.h"

Background::Background(const char* imagePath, string name_, int z_index, SDL_Renderer* rend, int widthImage, int heightImage, int screenWidth, int screenHeight) :
            GameObject(imagePath,name_, z_index, rend, 0, 0, screenWidth, screenHeight){

                imgHeight = heightImage;
                imgWight = widthImage;
                renderer = rend;

                CAMERA_WIDTH = screenWidth;
                CAMERA_HEIGHT = screenHeight;
                CAMERA_X_POS = (widthImage/2) - screenWidth/2;
                CAMERA_Y_POS = heightImage - screenHeight;

                camera = SDL_Rect{CAMERA_X_POS, CAMERA_Y_POS, CAMERA_WIDTH, CAMERA_HEIGHT};
            }

Background::~Background() = default;


void Background::render(){

    int error = SDL_RenderCopy(renderer, objTexture, &camera, &objRect);
    if( error < 0){
        cout << "error: " << SDL_GetError() << endl;
    }

}



void Background::updatePos(int posX, int posY) {

    camera.x = posX;
    camera.y = posY;
}
