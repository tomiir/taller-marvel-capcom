//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongDownPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 3;

    vector<int> frame0 = {491, 2680, 491, 268};
    vector<int> frame1 = {982, 2680, 491, 268};
    vector<int> frame2 = {1473, 2680, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

SpiderManStrongDownPunchAnimation::SpiderManStrongDownPunchAnimation() : Animation() {

    this->init();

}