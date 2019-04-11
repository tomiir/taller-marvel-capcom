//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaJumpAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 6;

    vector<int> frame0 = {5, 498, 77, 90};
    vector<int> frame1 = {112, 428, 71, 152};
    vector<int> frame2 = {210, 427, 71, 152};
    vector<int> frame3 = {304, 430, 89, 68};
    vector<int> frame4 = {414, 431, 75, 86};
    vector<int> frame5 = {499, 428, 89, 157};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);

}

CaptainAmericaJumpAnimation::CaptainAmericaJumpAnimation() : Animation() {

    this->init();

}