//
// Created by fer on 22/06/19.
//


#include "VenomGrabbedImpactAnimation.h"
#include <SDL_timer.h>



void VenomGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 5;


    vector<int> frame0 = {1120, 5236, 560, 238};
    vector<int> frame1 = {1680, 5236, 560, 238};
    vector<int> frame2 = {0, 714, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

VenomGrabbedImpactAnimation::VenomGrabbedImpactAnimation() : Animation() {

    this->init();

}