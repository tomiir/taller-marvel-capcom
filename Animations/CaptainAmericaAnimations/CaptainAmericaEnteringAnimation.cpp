//
// Created by arielpm on 13/04/19.
//

#include "CaptainAmericaEnteringAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;

    vector<int> frame0 = {383, 848, 383, 212};
    vector<int> frame1 = {766, 848, 383, 212};
    vector<int> frame2 = {1149, 848, 383, 212};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaEnteringAnimation::CaptainAmericaEnteringAnimation() : Animation() {

    this->init();

}