//
// Created by arielpm on 13/06/19.
//

#include "CaptainAmericaAirKickedAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaAirKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {322, 1225, 322, 245};


    animation.push_back(frame0);

}

CaptainAmericaAirKickedAnimation::CaptainAmericaAirKickedAnimation() : Animation() {

    this->init();

}