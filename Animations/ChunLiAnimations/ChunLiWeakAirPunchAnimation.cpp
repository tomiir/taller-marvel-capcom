//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakAirPunchAnimation.h"


void ChunLiWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 10;

    vector<int> frame0 = {0, 2520, 407, 210};
    vector<int> frame1 = {407, 2520, 407, 210};
    vector<int> frame2 = {814, 2520, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);

}

ChunLiWeakAirPunchAnimation::ChunLiWeakAirPunchAnimation() : Animation() {

    this->init();

}