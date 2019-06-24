//
// Created by fer on 22/06/19.
//

#include "CaptainAmericaGrabbedAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaGrabbedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 3;

    vector<int> frame0 = {0, 5390, 322, 245};
    vector<int> frame1 = {322, 5390, 322, 245};
    vector<int> frame2 = {644, 5390, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaGrabbedAnimation::CaptainAmericaGrabbedAnimation() : Animation() {

    this->init();

}