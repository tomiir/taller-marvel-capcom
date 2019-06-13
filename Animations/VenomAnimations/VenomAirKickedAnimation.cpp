//
// Created by arielpm on 13/06/19.
//

#include "VenomAirKickedAnimation.h"
#include <SDL_timer.h>


void VenomAirKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {560, 1190, 560, 238};


    animation.push_back(frame0);

}

VenomAirKickedAnimation::VenomAirKickedAnimation() : Animation() {

    this->init();

}