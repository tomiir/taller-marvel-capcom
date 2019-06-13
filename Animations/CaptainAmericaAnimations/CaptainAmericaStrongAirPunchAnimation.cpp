//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongAirPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 9 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaStrongAirPunchAnimation::CaptainAmericaStrongAirPunchAnimation() : Animation() {

    this->init();

}