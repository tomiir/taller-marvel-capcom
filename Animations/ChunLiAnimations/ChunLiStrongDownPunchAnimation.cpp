//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongDownPunchAnimation.h"

void ChunLiStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {814, 2100, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongDownPunchAnimation::ChunLiStrongDownPunchAnimation() : Animation() {

    this->init();

}