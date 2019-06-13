//
// Created by arielpm on 13/04/19.
//

#include "CaptainAmericaEnteringAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 4 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaEnteringAnimation::CaptainAmericaEnteringAnimation() : Animation() {

    this->init();

}