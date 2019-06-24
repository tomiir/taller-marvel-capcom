//
// Created by arielpm on 13/06/19.
//

#include "SpiderManDownGuardAnimation.h"

void SpiderManDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {491, 1876, 491, 268};

    animation.push_back(frame0);

}

SpiderManDownGuardAnimation::SpiderManDownGuardAnimation() : Animation() {

    this->init();

}