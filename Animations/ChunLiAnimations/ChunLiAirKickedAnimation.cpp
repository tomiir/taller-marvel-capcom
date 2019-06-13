//
// Created by arielpm on 13/06/19.
//

#include "ChunLiAirKickedAnimation.h"
#include <SDL_timer.h>

void ChunLiAirKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;


    vector<int> frame0 = {407, 1050, 407, 210};

    animation.push_back(frame0);
}

ChunLiAirKickedAnimation::ChunLiAirKickedAnimation() : Animation() {

    this->init();
}