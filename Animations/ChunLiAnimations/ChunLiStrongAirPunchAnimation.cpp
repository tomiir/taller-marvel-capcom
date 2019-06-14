//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongAirPunchAnimation.h"


void ChunLiStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 10;

    vector<int> frame0 = {0, 1890, 407, 210};
    vector<int> frame1 = {407, 1890, 407, 210};
    vector<int> frame2 = {814, 1890, 407, 210};


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

ChunLiStrongAirPunchAnimation::ChunLiStrongAirPunchAnimation() : Animation() {

    this->init();

}