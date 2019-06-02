//
// Created by fer on 01/06/19.
//

#include "SpiderManPunchAnimation.h"


void SpiderManPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 3;


    vector<int> frame1 = {582, 649, 103, 68};
    vector<int> frame2 = {17, 638, 109, 77};
    vector<int> frame3 = {129, 638, 152, 77};

    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManPunchAnimation::SpiderManPunchAnimation() : Animation() {

    this->init();

}