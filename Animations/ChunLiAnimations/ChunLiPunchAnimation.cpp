//
// Created by fer on 01/06/19.
//

#include "ChunLiPunchAnimation.h"


void ChunLiPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

//    vector<int> frame1 = {116, 1236, 115, 80};
    vector<int> frame2 = {241, 1233, 131, 84};

//    animation.push_back(frame1);
    animation.push_back(frame2);

}

ChunLiPunchAnimation::ChunLiPunchAnimation() : Animation() {

    this->init();

}
