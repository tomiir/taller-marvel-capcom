//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStandGuardAnimation.h"
#include <SDL_timer.h>

void ChunLiStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {814, 1260, 407, 210};

    animation.push_back(frame0);
}

ChunLiStandGuardAnimation::ChunLiStandGuardAnimation() : Animation() {

    this->init();
}