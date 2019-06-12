//
// Created by arielpm on 12/06/19.
//

#include "VenomKickedAnimation.h"
#include <SDL_timer.h>


void VenomKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;

    vector<int> frame0 = {0, 1190, 560, 238};
    vector<int> frame1 = {560, 1190, 560, 238};
    vector<int> frame2 = {1120, 1190, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

VenomKickedAnimation::VenomKickedAnimation() : Animation() {

    this->init();

}