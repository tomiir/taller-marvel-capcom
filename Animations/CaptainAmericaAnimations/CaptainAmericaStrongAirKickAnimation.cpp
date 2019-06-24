//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongAirKickAnimation.h"


void CaptainAmericaStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 8;

    vector<int> frame0 = {0, 4655, 322, 245};
    vector<int> frame1 = {322, 4655, 322, 245};
    vector<int> frame2 = {322, 4655, 322, 245};
    vector<int> frame3 = {322, 4655, 322, 245};
    vector<int> frame4 = {322, 4655, 322, 245};
    vector<int> frame5 = {322, 4655, 322, 245};
    vector<int> frame6 = {322, 4655, 322, 245};
    vector<int> frame7 = {322, 4655, 322, 245};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

CaptainAmericaStrongAirKickAnimation::CaptainAmericaStrongAirKickAnimation() : Animation() {

    this->init();

}