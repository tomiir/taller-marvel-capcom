//
// Created by fer on 01/06/19.
//

#include "ChunLiWeakStandPunchAnimation.h"


void ChunLiWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 10;

    vector<int> frame0 = {0, 2940, 407, 210};
    vector<int> frame1 = {407, 2940, 407, 210};
    vector<int> frame2 = {814, 2940, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);

}

ChunLiWeakStandPunchAnimation::ChunLiWeakStandPunchAnimation() : Animation() {

    this->init();

}
