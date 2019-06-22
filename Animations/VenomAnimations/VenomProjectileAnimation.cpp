//
// Created by arielpm on 22/06/19.
//

#include "VenomProjectileAnimation.h"

void VenomProjectileAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 3;

    vector<int> frame0 = {0, 0, 560, 238};
    vector<int> frame1 = {560, 0, 560, 238};
    vector<int> frame2 = {1120, 0, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

VenomProjectileAnimation::VenomProjectileAnimation() : Animation() {

    this->init();

}