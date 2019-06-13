//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakDownPunchAnimation.h"


void ChunLiWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 2730, 407, 210};

    animation.push_back(frame0);

}

ChunLiWeakDownPunchAnimation::ChunLiWeakDownPunchAnimation() : Animation() {

    this->init();

}