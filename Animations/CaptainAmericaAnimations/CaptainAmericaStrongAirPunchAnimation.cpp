//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongAirPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;

    vector<int> frame0 = {322, 2205, 322, 245};
    vector<int> frame1 = {644, 2205, 322, 245};
    vector<int> frame2 = {966, 2205, 322, 245};
    vector<int> frame3 = {1288, 2205, 322, 245};
    vector<int> frame4 = {1610, 2205, 322, 245};
    vector<int> frame5 = {1932, 2205, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);



}

CaptainAmericaStrongAirPunchAnimation::CaptainAmericaStrongAirPunchAnimation() : Animation() {

    this->init();

}