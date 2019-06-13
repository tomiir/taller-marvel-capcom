//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongStandKickAnimation.h"

void ChunLiStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {1221, 3780, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongStandKickAnimation::ChunLiStrongStandKickAnimation() : Animation() {

    this->init();

}