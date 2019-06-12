//
// Created by fer on 01/06/19.
//

#include "VenomWeakStandPunchAnimation.h"

void VenomWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame2 = {560, 3332, 560, 238};

    animation.push_back(frame2);

}

VenomWeakStandPunchAnimation::VenomWeakStandPunchAnimation() : Animation() {

    this->init();

}