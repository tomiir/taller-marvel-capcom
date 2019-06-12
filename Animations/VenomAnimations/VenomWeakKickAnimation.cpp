//
// Created by arielpm on 12/06/19.
//

#include "VenomWeakKickAnimation.h"


void VenomWeakKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame2 = {560, 3570, 560, 238};

    animation.push_back(frame2);

}

VenomWeakKickAnimation::VenomWeakKickAnimation() : Animation() {

    this->init();

}