//
// Created by fer on 01/06/19.
//

#include "VenomPunchAnimation.h"

void VenomPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame2 = {560, 3332, 560, 238};

    animation.push_back(frame2);

}

VenomPunchAnimation::VenomPunchAnimation() : Animation() {

    this->init();

}