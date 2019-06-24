//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaGrabAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaGrabAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 4;

    vector<int> frame0 = {0, 5145, 322, 245};
    vector<int> frame1 = {322, 5145, 322, 245};
    vector<int> frame2 = {644, 5145, 322, 245};
    vector<int> frame3 = {966, 5145, 322, 245};
    vector<int> frame4 = {1288, 5145, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

CaptainAmericaGrabAnimation::CaptainAmericaGrabAnimation() : Animation() {

    this->init();

}