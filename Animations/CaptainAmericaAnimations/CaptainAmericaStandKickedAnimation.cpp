//
// Created by arielpm on 13/06/19.
//

#include "CaptainAmericaStandKickedAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {644, 1225, 322, 245};


    animation.push_back(frame0);

}

CaptainAmericaStandKickedAnimation::CaptainAmericaStandKickedAnimation() : Animation() {

    this->init();

}