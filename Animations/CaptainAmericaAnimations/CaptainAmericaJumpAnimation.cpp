//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaJumpAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 20;
    animationLength = 4;

    vector<int> frame0 = {0, 980, 322, 245};
    vector<int> frame1 = {322, 980, 322, 245};
    vector<int> frame2 = {644, 980, 322, 245};
    vector<int> frame3 = {966, 980, 322, 245};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

CaptainAmericaJumpAnimation::CaptainAmericaJumpAnimation() : Animation() {

    this->init();

}