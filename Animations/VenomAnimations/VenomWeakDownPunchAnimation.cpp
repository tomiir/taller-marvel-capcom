//
// Created by arielpm on 12/06/19.
//

#include "VenomWeakDownPunchAnimation.h"

void VenomWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame2 = {560, 3094, 560, 238};

    animation.push_back(frame2);

}

VenomWeakDownPunchAnimation::VenomWeakDownPunchAnimation() : Animation() {

    this->init();

}