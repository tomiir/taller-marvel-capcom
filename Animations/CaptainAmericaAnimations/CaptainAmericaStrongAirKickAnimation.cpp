//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongAirKickAnimation.h"


void CaptainAmericaStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 4655, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaStrongAirKickAnimation::CaptainAmericaStrongAirKickAnimation() : Animation() {

    this->init();

}