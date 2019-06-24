//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakDownKickAnimation.h"

void CaptainAmericaWeakDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;

    vector<int> frame0 = {0, 4165, 322, 245};
    vector<int> frame1 = {322, 4165, 322, 245};
    vector<int> frame2 = {322, 4165, 322, 245};
    vector<int> frame3 = {322, 4165, 322, 245};
    vector<int> frame4 = {322, 4165, 322, 245};
    vector<int> frame5 = {322, 4165, 322, 245};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);

}

CaptainAmericaWeakDownKickAnimation::CaptainAmericaWeakDownKickAnimation() : Animation() {

    this->init();

}
