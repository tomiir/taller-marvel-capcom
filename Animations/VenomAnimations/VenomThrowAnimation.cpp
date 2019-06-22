//
// Created by arielpm on 21/06/19.
//

#include "VenomThrowAnimation.h"
#include <SDL_timer.h>


void VenomThrowAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 3;

    vector<int> frame0 = {0, 5474, 560, 238};
    vector<int> frame1 = {560, 5474, 560, 238};
    vector<int> frame2 = {1120, 5474, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
}

VenomThrowAnimation::VenomThrowAnimation() : Animation() {

    this->init();

}