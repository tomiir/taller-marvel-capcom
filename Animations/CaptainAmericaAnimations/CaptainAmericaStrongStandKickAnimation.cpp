//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongStandKickAnimation.h"



void CaptainAmericaStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;

    vector<int> frame0 = {0, 4410, 322, 245};
    vector<int> frame1 = {322, 4410, 322, 245};
    vector<int> frame2 = {644, 4410, 322, 245};
    vector<int> frame3 = {644, 4410, 322, 245};
    vector<int> frame4 = {644, 4410, 322, 245};
    vector<int> frame5 = {644, 4410, 322, 245};
    vector<int> frame6 = {644, 4410, 322, 245};
    vector<int> frame7 = {966, 4410, 322, 245};
    vector<int> frame8 = {1288, 4410, 322, 245};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);

}

CaptainAmericaStrongStandKickAnimation::CaptainAmericaStrongStandKickAnimation() : Animation() {

    this->init();

}