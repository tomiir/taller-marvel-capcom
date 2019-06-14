//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakAirKickAnimation.h"


void CaptainAmericaWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 7;

    vector<int> frame0 = {0, 3920, 322, 245};
    vector<int> frame1 = {322, 3920, 322, 245};
    vector<int> frame2 = {322, 3920, 322, 245};
    vector<int> frame3 = {322, 3920, 322, 245};
    vector<int> frame4 = {322, 3920, 322, 245};
    vector<int> frame5 = {322, 3920, 322, 245};
    vector<int> frame6 = {322, 3920, 322, 245};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);

}

CaptainAmericaWeakAirKickAnimation::CaptainAmericaWeakAirKickAnimation() : Animation() {

    this->init();

}