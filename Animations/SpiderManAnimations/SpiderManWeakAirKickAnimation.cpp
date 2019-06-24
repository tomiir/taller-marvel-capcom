//
// Created by arielpm on 13/06/19.
//

#include "SpiderManWeakAirKickAnimation.h"

void SpiderManWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;


    vector<int> frame0 = {0, 4288, 491, 268};
    vector<int> frame1 = {491, 4288, 491, 268};
    vector<int> frame2 = {982, 4288, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

SpiderManWeakAirKickAnimation::SpiderManWeakAirKickAnimation() : Animation() {

    this->init();

}