//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongAirPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 13;

    vector<int> frame0 = {0, 2205, 322, 245};
    vector<int> frame1 = {322, 2205, 322, 245};
    vector<int> frame2 = {644, 2205, 322, 245};
    vector<int> frame3 = {966, 2205, 322, 245};
    vector<int> frame4 = {966, 2205, 322, 245};
    vector<int> frame5 = {966, 2205, 322, 245};
    vector<int> frame6 = {1288, 2205, 322, 245};
    vector<int> frame7 = {1288, 2205, 322, 245};
    vector<int> frame8 = {1288, 2205, 322, 245};
    vector<int> frame9 = {1610, 2205, 322, 245};
    vector<int> frame10 = {1610, 2205, 322, 245};
    vector<int> frame11 = {1610, 2205, 322, 245};
    vector<int> frame12 = {1932, 2205, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame9);
    animation.push_back(frame10);
    animation.push_back(frame11);
    animation.push_back(frame12);


}

CaptainAmericaStrongAirPunchAnimation::CaptainAmericaStrongAirPunchAnimation() : Animation() {

    this->init();

}