//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakStandKickAnimation.h"


void CaptainAmericaWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 15 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaWeakStandKickAnimation::CaptainAmericaWeakStandKickAnimation() : Animation() {

    this->init();

}