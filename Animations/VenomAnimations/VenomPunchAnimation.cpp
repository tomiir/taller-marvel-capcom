//
// Created by fer on 01/06/19.
//

#include "VenomPunchAnimation.h"

void VenomPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 2;

    vector<int> frame1 = {4, 843, 131, 93};
    vector<int> frame2 = {168, 843, 215, 93};

    animation.push_back(frame1);
    animation.push_back(frame2);

}

VenomPunchAnimation::VenomPunchAnimation() : Animation() {

    this->init();

}