//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaDownKickedAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaDownKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;

    vector<int> frame0 = {0, 1225, 322, 245};


    animation.push_back(frame0);

}

CaptainAmericaDownKickedAnimation::CaptainAmericaDownKickedAnimation() : Animation() {

    this->init();

}