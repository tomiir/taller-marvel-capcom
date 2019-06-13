//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongDownKickAnimation.h"


void SpiderManStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 5;


    vector<int> frame0 = {491, 5360, 491, 268};
    vector<int> frame1 = {982, 5360, 491, 268};
    vector<int> frame2 = {1473, 5360, 491, 268};
    vector<int> frame3 = {1964, 5360, 491, 268};
    vector<int> frame4 = {2455, 5360, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

SpiderManStrongDownKickAnimation::SpiderManStrongDownKickAnimation() : Animation() {

    this->init();

}