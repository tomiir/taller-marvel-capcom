//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakAirKickAnimation.h"

void ChunLiWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 3360, 407, 210};

    animation.push_back(frame0);

}

ChunLiWeakAirKickAnimation::ChunLiWeakAirKickAnimation() : Animation() {

    this->init();

}