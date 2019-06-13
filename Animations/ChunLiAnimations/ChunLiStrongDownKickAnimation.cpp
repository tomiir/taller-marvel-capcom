//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongDownKickAnimation.h"

void ChunLiStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 4200, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongDownKickAnimation::ChunLiStrongDownKickAnimation() : Animation() {

    this->init();

}