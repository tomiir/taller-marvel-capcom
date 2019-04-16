//
// Created by arielpm on 13/04/19.
//

#include "VenomEnteringAnimation.h"
#include <SDL_timer.h>


void VenomEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 4;

    vector<int> frame0 = {206, 5415, 133, 153};
    vector<int> frame1 = {354, 5406, 127, 162};
    vector<int> frame2 = {3, 5588, 131, 136};
    vector<int> frame3 = {148, 5581, 130, 144};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);


}

VenomEnteringAnimation::VenomEnteringAnimation() : Animation() {

    this->init();

}