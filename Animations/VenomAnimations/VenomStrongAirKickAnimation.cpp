//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongAirKickAnimation.h"

void VenomStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 2;

    vector<int> frame0 = {2800, 4522, 560, 238};
    vector<int> frame1 = {3360, 4522, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);

}

VenomStrongAirKickAnimation::VenomStrongAirKickAnimation() : Animation() {

    this->init();

}