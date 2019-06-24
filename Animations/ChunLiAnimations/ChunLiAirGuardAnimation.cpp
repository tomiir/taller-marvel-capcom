//
// Created by arielpm on 13/06/19.
//

#include "ChunLiAirGuardAnimation.h"
#include <SDL_timer.h>

void ChunLiAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {407, 1680, 407, 210};

    animation.push_back(frame0);
}

ChunLiAirGuardAnimation::ChunLiAirGuardAnimation() : Animation() {

    this->init();
}