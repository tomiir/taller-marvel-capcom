//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongStandKickAnimation.h"


void VenomStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame2 = {2240, 3808, 560, 238};

    animation.push_back(frame2);

}

VenomStrongStandKickAnimation::VenomStrongStandKickAnimation() : Animation() {

    this->init();

}