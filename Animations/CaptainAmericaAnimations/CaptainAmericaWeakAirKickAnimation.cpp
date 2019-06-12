//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakAirKickAnimation.h"


void CaptainAmericaWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 3920, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaWeakAirKickAnimation::CaptainAmericaWeakAirKickAnimation() : Animation() {

    this->init();

}