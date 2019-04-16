//
// Created by arielpm on 13/04/19.
//

#include "CaptainAmericaEnteringAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;

    vector<int> frame0 = {456, 1913, 79, 138};
    vector<int> frame1 = {112, 428, 71, 152};
    vector<int> frame2 = {210, 427, 71, 152};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaEnteringAnimation::CaptainAmericaEnteringAnimation() : Animation() {

    this->init();

}