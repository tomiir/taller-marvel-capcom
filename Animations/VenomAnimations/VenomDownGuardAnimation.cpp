//
// Created by arielpm on 12/06/19.
//

#include "VenomDownGuardAnimation.h"

void VenomDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {560, 1666, 560, 238};


    animation.push_back(frame0);

}

VenomDownGuardAnimation::VenomDownGuardAnimation() : Animation() {

    this->init();

}