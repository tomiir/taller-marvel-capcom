//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakStandKickAnimation.h"


void CaptainAmericaWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 7;

    vector<int> frame0 = {0, 3675, 322, 245};
    vector<int> frame1 = {322, 3675, 322, 245};
    vector<int> frame2 = {322, 3675, 322, 245};
    vector<int> frame3 = {322, 3675, 322, 245};
    vector<int> frame4 = {322, 3675, 322, 245};
    vector<int> frame5 = {322, 3675, 322, 245};
    vector<int> frame6 = {644, 3675, 322, 245};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);

}

CaptainAmericaWeakStandKickAnimation::CaptainAmericaWeakStandKickAnimation() : Animation() {

    this->init();

}