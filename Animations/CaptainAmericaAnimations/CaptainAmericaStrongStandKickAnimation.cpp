//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongStandKickAnimation.h"



void CaptainAmericaStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 4410, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaStrongStandKickAnimation::CaptainAmericaStrongStandKickAnimation() : Animation() {

    this->init();

}