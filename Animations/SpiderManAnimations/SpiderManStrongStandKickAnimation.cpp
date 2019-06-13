//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongStandKickAnimation.h"

void SpiderManStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 4;


    vector<int> frame0 = {982, 4824, 491, 268};
    vector<int> frame1 = {1473, 4824, 491, 268};
    vector<int> frame2 = {1964, 4824, 491, 268};
    vector<int> frame3 = {2455, 4824, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManStrongStandKickAnimation::SpiderManStrongStandKickAnimation() : Animation() {

    this->init();

}