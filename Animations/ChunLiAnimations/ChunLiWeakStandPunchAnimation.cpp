//
// Created by fer on 01/06/19.
//

#include "ChunLiWeakStandPunchAnimation.h"


void ChunLiWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

//    vector<int> frame1 = {116, 1236, 115, 80};
    vector<int> frame2 = {407, 2940, 407, 210};

//    animation.push_back(frame1);
    animation.push_back(frame2);

}

ChunLiWeakStandPunchAnimation::ChunLiWeakStandPunchAnimation() : Animation() {

    this->init();

}
