//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakStandKickAnimation.h"

void SpiderManWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;


    vector<int> frame0 = {0, 4020, 491, 268};
    vector<int> frame1 = {491, 4020, 491, 268};
    vector<int> frame2 = {982, 4020, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

SpiderManWeakStandKickAnimation::SpiderManWeakStandKickAnimation() : Animation() {

    this->init();

}