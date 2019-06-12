//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaKickedAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;

    vector<int> frame0 = {0, 1225, 322, 245};
    vector<int> frame1 = {322, 1225, 322, 245};
    vector<int> frame2 = {644, 1225, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaKickedAnimation::CaptainAmericaKickedAnimation() : Animation() {

    this->init();

}