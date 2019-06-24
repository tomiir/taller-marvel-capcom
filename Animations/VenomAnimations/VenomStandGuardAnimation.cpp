//
// Created by arielpm on 12/06/19.
//

#include "VenomStandGuardAnimation.h"

void VenomStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {560, 1428, 560, 238};


    animation.push_back(frame0);

}

VenomStandGuardAnimation::VenomStandGuardAnimation() : Animation() {

    this->init();

}