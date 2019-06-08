//
// Created by arielpm on 13/04/19.
//

#include "VenomEnteringAnimation.h"
#include <SDL_timer.h>


void VenomEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;

    vector<int> frame0 = {2800, 952, 560, 238};
    vector<int> frame1 = {3360, 952, 560, 238};
    vector<int> frame2 = {3920, 952, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);


}

VenomEnteringAnimation::VenomEnteringAnimation() : Animation() {

    this->init();

}