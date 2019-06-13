//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakAirKickAnimation.h"


void CaptainAmericaWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 16 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaWeakAirKickAnimation::CaptainAmericaWeakAirKickAnimation() : Animation() {

    this->init();

}