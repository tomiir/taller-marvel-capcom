//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakAirPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 2940, 322, 245};

    animation.push_back(frame0);


}

CaptainAmericaWeakAirPunchAnimation::CaptainAmericaWeakAirPunchAnimation() : Animation() {

    this->init();

}