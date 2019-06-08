//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaJumpAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 5;

    vector<int> frame0 = {383, 848, 383, 212};
    vector<int> frame1 = {766, 848, 383, 212};
    vector<int> frame2 = {1149, 848, 383, 212};
    vector<int> frame3 = {1532, 848, 383, 212};
    vector<int> frame4 = {1915, 848, 383, 212};
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