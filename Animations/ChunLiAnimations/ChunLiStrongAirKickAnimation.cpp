//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongAirKickAnimation.h"

void ChunLiStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 3990, 407, 210};

    animation.push_back(frame0);

}

ChunLiStrongAirKickAnimation::ChunLiStrongAirKickAnimation() : Animation() {

    this->init();

}