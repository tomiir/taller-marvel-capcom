//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStandGuardAnimation.h"

void SpiderManStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {491, 1608, 491, 268};

    animation.push_back(frame0);

}

SpiderManStandGuardAnimation::SpiderManStandGuardAnimation() : Animation() {

    this->init();

}