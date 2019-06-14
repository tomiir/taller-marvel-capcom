//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakDownPunchAnimation.h"


void SpiderManWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;


    vector<int> frame0 = {0, 3484, 491, 268};
    vector<int> frame1 = {491, 3484, 491, 268};
    vector<int> frame2 = {982, 3484, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

SpiderManWeakDownPunchAnimation::SpiderManWeakDownPunchAnimation() : Animation() {

    this->init();

}