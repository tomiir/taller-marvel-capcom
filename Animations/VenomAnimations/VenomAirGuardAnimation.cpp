//
// Created by arielpm on 12/06/19.
//

#include "VenomAirGuardAnimation.h"

void VenomAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {560, 1904, 560, 238};


    animation.push_back(frame0);

}

VenomAirGuardAnimation::VenomAirGuardAnimation() : Animation() {

    this->init();

}