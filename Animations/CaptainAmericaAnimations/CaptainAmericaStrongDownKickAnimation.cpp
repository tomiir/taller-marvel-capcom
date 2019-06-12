//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongDownKickAnimation.h"


void CaptainAmericaStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 4900, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaStrongDownKickAnimation::CaptainAmericaStrongDownKickAnimation() : Animation() {

    this->init();

}