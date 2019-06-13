//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongDownKickAnimation.h"


void CaptainAmericaStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 2;
    int width = 322;
    int height = 245;
    int initialX = 2 * width;
    int initialY = 20 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaStrongDownKickAnimation::CaptainAmericaStrongDownKickAnimation() : Animation() {

    this->init();

}