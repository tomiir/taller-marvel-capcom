//
// Created by arielpm on 13/06/19.
//

#include "VenomStandKickedAnimation.h"
#include <SDL_timer.h>


void VenomStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {1120, 1190, 560, 238};


    animation.push_back(frame0);

}

VenomStandKickedAnimation::VenomStandKickedAnimation() : Animation() {

    this->init();

}