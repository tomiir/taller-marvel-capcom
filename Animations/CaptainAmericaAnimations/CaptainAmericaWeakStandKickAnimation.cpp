//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakStandKickAnimation.h"


void CaptainAmericaWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 3675, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaWeakStandKickAnimation::CaptainAmericaWeakStandKickAnimation() : Animation() {

    this->init();

}