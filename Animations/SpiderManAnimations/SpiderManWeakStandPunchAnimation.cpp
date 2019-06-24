//
// Created by fer on 01/06/19.
//

#include "SpiderManWeakStandPunchAnimation.h"


void SpiderManWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 7;


    vector<int> frame0 = {0, 3752, 491, 268};
    vector<int> frame1 = {491, 3752, 491, 268};
    vector<int> frame2 = {982, 3752, 491, 268};
    vector<int> frame3 = {1473, 3752, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManWeakStandPunchAnimation::SpiderManWeakStandPunchAnimation() : Animation() {

    this->init();

}