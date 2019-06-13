//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongStandPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 4;

    vector<int> frame0 = {982, 2948, 491, 268};
    vector<int> frame1 = {1473, 2948, 491, 268};
    vector<int> frame2 = {1964, 2948, 491, 268};
    vector<int> frame3 = {2455, 2948, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManStrongStandPunchAnimation::SpiderManStrongStandPunchAnimation() : Animation() {

    this->init();

}