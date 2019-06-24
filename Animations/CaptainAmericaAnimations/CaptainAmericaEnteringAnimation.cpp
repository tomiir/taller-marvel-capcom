//
// Created by arielpm on 13/04/19.
//

#include "CaptainAmericaEnteringAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 30;
    animationLength = 3;

    vector<int> frame0 = {322, 980, 322, 245};
    vector<int> frame1 = {644, 980, 322, 245};
    vector<int> frame2 = {966, 980, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaEnteringAnimation::CaptainAmericaEnteringAnimation() : Animation() {

    this->init();

}