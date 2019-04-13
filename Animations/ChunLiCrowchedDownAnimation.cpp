//
// Created by arielpm on 13/04/19.
//

#include "ChunLiCrowchedDownAnimation.h"
#include <SDL_timer.h>

void ChunLiCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 2;

    vector<int> frame0 = {799, 250, 86, 72};
    vector<int> frame1 = {898, 254, 86, 70};


    animation.push_back(frame0);
    animation.push_back(frame1);

}

ChunLiCrowchedDownAnimation::ChunLiCrowchedDownAnimation() : Animation() {

    this->init();

}