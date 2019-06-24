//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaCrowchedDownAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;

    vector<int> frame0 = {0, 735, 322, 245};



    animation.push_back(frame0);

}

CaptainAmericaCrowchedDownAnimation::CaptainAmericaCrowchedDownAnimation() : Animation() {

    this->init();

}

