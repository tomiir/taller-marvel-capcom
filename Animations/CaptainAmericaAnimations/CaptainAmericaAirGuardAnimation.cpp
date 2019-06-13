//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaAirGuardAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 1960, 322, 245};

    animation.push_back(frame0);


}

CaptainAmericaAirGuardAnimation::CaptainAmericaAirGuardAnimation() : Animation() {

    this->init();

}