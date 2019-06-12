//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongStandPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;

    vector<int> frame0 = {0, 2695, 322, 245};
    vector<int> frame1 = {322, 2695, 322, 245};
    vector<int> frame2 = {644, 2695, 322, 245};
    vector<int> frame3 = {966, 2695, 322, 245};
    vector<int> frame4 = {1288, 2695, 322, 245};
    vector<int> frame5 = {1610, 2695, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);



}

CaptainAmericaStrongStandPunchAnimation::CaptainAmericaStrongStandPunchAnimation() : Animation() {

    this->init();

}