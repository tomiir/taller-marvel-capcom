//
// Created by arielpm on 13/06/19.
//

#include "ChunLiDownGuardAnimation.h"
#include <SDL_timer.h>

void ChunLiDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {407, 1470, 407, 210};

    animation.push_back(frame0);
}

ChunLiDownGuardAnimation::ChunLiDownGuardAnimation() : Animation() {

    this->init();
}