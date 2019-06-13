//
// Created by arielpm on 13/06/19.
//

#include "ChunLiDownKickedAnimation.h"
#include <SDL_timer.h>

void ChunLiDownKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {0, 1050, 407, 210};

    animation.push_back(frame0);
}

ChunLiDownKickedAnimation::ChunLiDownKickedAnimation() : Animation() {

    this->init();
}