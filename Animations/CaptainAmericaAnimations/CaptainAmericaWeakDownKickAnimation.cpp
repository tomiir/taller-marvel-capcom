//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakDownKickAnimation.h"

void CaptainAmericaWeakDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 4165, 322, 245};

    animation.push_back(frame0);

}

CaptainAmericaWeakDownKickAnimation::CaptainAmericaWeakDownKickAnimation() : Animation() {

    this->init();

}
