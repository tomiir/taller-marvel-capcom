//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongAirPunchAnimation.h"

void VenomStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 2;

    vector<int> frame0 = {1680, 2142, 560, 238};
    vector<int> frame1 = {2240, 2142, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);

}

VenomStrongAirPunchAnimation::VenomStrongAirPunchAnimation() : Animation() {

    this->init();

}