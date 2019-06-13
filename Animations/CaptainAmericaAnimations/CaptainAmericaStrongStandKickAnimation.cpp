//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongStandKickAnimation.h"



void CaptainAmericaStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 5;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 18 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaStrongStandKickAnimation::CaptainAmericaStrongStandKickAnimation() : Animation() {

    this->init();

}