//
// Created by fer on 22/06/19.
//


#include "VenomGrabbedImpactAnimation.h"
#include <SDL_timer.h>



void VenomGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 20;
    animationLength = 2;


    vector<int> frame0 = {1120, 5236, 560, 238};
    vector<int> frame1 = {1680, 5236, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);

}

VenomGrabbedImpactAnimation::VenomGrabbedImpactAnimation() : Animation() {

    this->init();

}