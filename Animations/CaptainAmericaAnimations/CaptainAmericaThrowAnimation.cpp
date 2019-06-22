//
// Created by arielpm on 21/06/19.
//

#include "CaptainAmericaThrowAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaThrowAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 3;

    vector<int> frame0 = {0, 5635, 322, 245};
    vector<int> frame1 = {322, 5635, 322, 245};
    vector<int> frame2 = {644, 5635, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaThrowAnimation::CaptainAmericaThrowAnimation() : Animation() {

    this->init();

}