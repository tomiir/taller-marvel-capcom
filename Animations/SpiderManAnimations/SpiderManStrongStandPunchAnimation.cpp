//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongStandPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 9;

    vector<int> frame0 = {0, 2948, 491, 268};
    vector<int> frame1 = {491, 2948, 491, 268};
    vector<int> frame2 = {982, 2948, 491, 268};
    vector<int> frame3 = {1473, 2948, 491, 268};
    vector<int> frame4 = {1964, 2948, 491, 268};
    vector<int> frame5 = {2455, 2948, 491, 268};
    vector<int> frame6 = {2946, 2948, 491, 268};
    vector<int> frame7 = {3437, 2948, 491, 268};
    vector<int> frame8 = {3928, 2948, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);

}

SpiderManStrongStandPunchAnimation::SpiderManStrongStandPunchAnimation() : Animation() {

    this->init();

}