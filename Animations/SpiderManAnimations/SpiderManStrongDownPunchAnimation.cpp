//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongDownPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 5;

    vector<int> frame0 = {0, 2680, 491, 268};
    vector<int> frame1 = {491, 2680, 491, 268};
    vector<int> frame2 = {982, 2680, 491, 268};
    vector<int> frame3 = {1473, 2680, 491, 268};
    vector<int> frame4 = {1964, 2680, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

SpiderManStrongDownPunchAnimation::SpiderManStrongDownPunchAnimation() : Animation() {

    this->init();

}