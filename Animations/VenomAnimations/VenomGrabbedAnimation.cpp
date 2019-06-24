//
// Created by fer on 22/06/19.
//

#include "VenomGrabbedAnimation.h"

#include <SDL_timer.h>



void VenomGrabbedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 2;

    vector<int> frame0 = {0, 5236, 560, 238};
    vector<int> frame1 = {560, 5236, 560, 238};

    animation.push_back(frame0);
    animation.push_back(frame1);

}

VenomGrabbedAnimation::VenomGrabbedAnimation() : Animation() {

    this->init();

}