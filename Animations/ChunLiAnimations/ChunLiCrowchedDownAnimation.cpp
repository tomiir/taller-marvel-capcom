//
// Created by arielpm on 13/04/19.
//

#include "ChunLiCrowchedDownAnimation.h"
#include <SDL_timer.h>

void ChunLiCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 32;
    animationLength = 2;

    vector<int> frame0 = {407, 630, 407, 210};
    vector<int> frame1 = {814, 630, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);

}

ChunLiCrowchedDownAnimation::ChunLiCrowchedDownAnimation() : Animation() {

    this->init();

}