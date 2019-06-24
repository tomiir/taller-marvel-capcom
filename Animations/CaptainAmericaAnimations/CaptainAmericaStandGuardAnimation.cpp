//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStandGuardAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 1470, 322, 245};


    animation.push_back(frame0);

}

CaptainAmericaStandGuardAnimation::CaptainAmericaStandGuardAnimation() : Animation() {

    this->init();

}