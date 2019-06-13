//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakDownKickAnimation.h"

void SpiderManWeakDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;


    vector<int> frame0 = {491, 4556, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakDownKickAnimation::SpiderManWeakDownKickAnimation() : Animation() {

    this->init();

}