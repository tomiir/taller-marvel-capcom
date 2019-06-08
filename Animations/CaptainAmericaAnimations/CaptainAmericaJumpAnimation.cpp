//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaJumpAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 5;

    vector<int> frame0 = {322, 980, 322, 245};
    vector<int> frame1 = {644, 980, 322, 245};
    vector<int> frame2 = {966, 980, 322, 245};
    vector<int> frame3 = {1288, 980, 322, 245};
    vector<int> frame4 = {1610, 980, 322, 245};
    //vector<int> frame5 = {499, 428, 89, 157};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    //animation.push_back(frame5);

}

CaptainAmericaJumpAnimation::CaptainAmericaJumpAnimation() : Animation() {

    this->init();

}