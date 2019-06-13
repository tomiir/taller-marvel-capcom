//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongAirPunchAnimation.h"


void ChunLiStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {814, 1890, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongAirPunchAnimation::ChunLiStrongAirPunchAnimation() : Animation() {

    this->init();

}