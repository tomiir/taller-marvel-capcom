//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongDownKickAnimation.h"


void VenomStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame2 = {1120, 4284, 560, 238};

    animation.push_back(frame2);

}

VenomStrongDownKickAnimation::VenomStrongDownKickAnimation() : Animation() {

    this->init();

}