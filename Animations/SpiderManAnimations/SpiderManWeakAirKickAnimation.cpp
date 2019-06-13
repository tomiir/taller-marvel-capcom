//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakAirKickAnimation.h"

void SpiderManWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;


    vector<int> frame0 = {491, 4288, 491, 268};

    animation.push_back(frame0);

}

SpiderManWeakAirKickAnimation::SpiderManWeakAirKickAnimation() : Animation() {

    this->init();

}