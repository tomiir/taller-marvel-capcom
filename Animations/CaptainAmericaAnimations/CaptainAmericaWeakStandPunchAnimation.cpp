//
// Created by trocchi on 6/1/19.
//

#include "CaptainAmericaWeakStandPunchAnimation.h"
#include <SDL_timer.h>


void CaptainAmericaWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 15;
    animationLength = 10;

    vector<int> frame0 = {0, 3430, 322, 245};
    vector<int> frame1 = {322, 3430, 322, 245};
    vector<int> frame2 = {644, 3430, 322, 245};
    vector<int> frame3 = {644, 3430, 322, 245};
    vector<int> frame4 = {644, 3430, 322, 245};
    vector<int> frame5 = {644, 3430, 322, 245};
    vector<int> frame6 = {644, 3430, 322, 245};
    vector<int> frame7 = {644, 3430, 322, 245};
    vector<int> frame8 = {644, 3430, 322, 245};
    vector<int> frame9 = {644, 3430, 322, 245};

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

}

CaptainAmericaWeakStandPunchAnimation::CaptainAmericaWeakStandPunchAnimation() : Animation() {

    this->init();

}
