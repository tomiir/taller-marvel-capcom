//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakAirPunchAnimation.h"


void SpiderManWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;


    vector<int> frame0 = {491, 3216, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakAirPunchAnimation::SpiderManWeakAirPunchAnimation() : Animation() {

    this->init();

}