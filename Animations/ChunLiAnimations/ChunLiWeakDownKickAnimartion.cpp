//
// Created by arielpm on 13/06/19.
//

#include "ChunLiWeakDownKickAnimartion.h"

void ChunLiWeakDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {814, 3570, 407, 210};

    animation.push_back(frame0);

}

ChunLiWeakDownKickAnimation::ChunLiWeakDownKickAnimation() : Animation() {

    this->init();

}