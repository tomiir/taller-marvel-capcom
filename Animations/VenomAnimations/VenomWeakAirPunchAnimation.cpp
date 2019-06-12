//
// Created by arielpm on 12/06/19.
//

#include "VenomWeakAirPunchAnimation.h"


void VenomWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame2 = {560, 2856, 560, 238};

    animation.push_back(frame2);

}

VenomWeakAirPunchAnimation::VenomWeakAirPunchAnimation() : Animation() {

    this->init();

}