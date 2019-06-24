//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaDownGuardAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 1715, 322, 245};

    animation.push_back(frame0);


}

CaptainAmericaDownGuardAnimation::CaptainAmericaDownGuardAnimation() : Animation() {

    this->init();

}