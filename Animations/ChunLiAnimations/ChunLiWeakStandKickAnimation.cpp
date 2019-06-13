//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakStandKickAnimation.h"

void ChunLiWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {1221, 3150, 407, 210};

    animation.push_back(frame0);

}

ChunLiWeakStandKickAnimation::ChunLiWeakStandKickAnimation() : Animation() {

    this->init();

}