//
// Created by fer on 01/06/19.
//

#include "SpiderManWeakStandPunchAnimation.h"


void SpiderManWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {491, 3752, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakStandPunchAnimation::SpiderManWeakStandPunchAnimation() : Animation() {

    this->init();

}