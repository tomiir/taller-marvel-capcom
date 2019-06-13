//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStandKickedAnimation.h"
#include <SDL_timer.h>

void ChunLiStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {814, 1050, 407, 210};

    animation.push_back(frame0);
}

ChunLiStandKickedAnimation::ChunLiStandKickedAnimation() : Animation() {

    this->init();
}