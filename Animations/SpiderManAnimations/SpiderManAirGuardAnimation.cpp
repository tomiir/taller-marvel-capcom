//
// Created by arielpm on 13/06/19.
//

#include "SpiderManAirGuardAnimation.h"


void SpiderManAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {491, 2144, 491, 268};

    animation.push_back(frame0);

}

SpiderManAirGuardAnimation::SpiderManAirGuardAnimation() : Animation() {

    this->init();

}