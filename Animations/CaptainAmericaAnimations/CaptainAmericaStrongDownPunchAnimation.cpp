//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongDownPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 3;

    vector<int> frame0 = {0, 2450, 322, 245};
    vector<int> frame1 = {322, 2450, 322, 245};
    vector<int> frame2 = {644, 2450, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);



}

CaptainAmericaStrongDownPunchAnimation::CaptainAmericaStrongDownPunchAnimation() : Animation() {

    this->init();

}