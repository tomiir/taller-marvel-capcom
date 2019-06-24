//
// Created by arielpm on 12/06/19.
//

#include "VenomDownKickedAnimation.h"
#include <SDL_timer.h>


void VenomDownKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {0, 1190, 560, 238};


    animation.push_back(frame0);

}

VenomDownKickedAnimation::VenomDownKickedAnimation() : Animation() {

    this->init();

}