//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakStandKickAnimation.h"

void SpiderManWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;


    vector<int> frame0 = {491, 4020, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakStandKickAnimation::SpiderManWeakStandKickAnimation() : Animation() {

    this->init();

}