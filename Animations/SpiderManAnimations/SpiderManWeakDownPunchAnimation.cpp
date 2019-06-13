//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakDownPunchAnimation.h"


void SpiderManWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;


    vector<int> frame0 = {491, 3484, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakDownPunchAnimation::SpiderManWeakDownPunchAnimation() : Animation() {

    this->init();

}