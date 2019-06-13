//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongStandPunchAnimaiton.h"

void ChunLiStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {814, 2310, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongStandPunchAnimation::ChunLiStrongStandPunchAnimation() : Animation() {

    this->init();

}