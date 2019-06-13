//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakAirPunchAnimation.h"


void ChunLiWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 2520, 407, 210};

    animation.push_back(frame0);

}

ChunLiWeakAirPunchAnimation::ChunLiWeakAirPunchAnimation() : Animation() {

    this->init();

}