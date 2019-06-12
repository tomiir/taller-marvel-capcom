//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakDownPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 3185, 322, 245};

    animation.push_back(frame0);


}

CaptainAmericaWeakDownPunchAnimation::CaptainAmericaWeakDownPunchAnimation() : Animation() {

    this->init();

}