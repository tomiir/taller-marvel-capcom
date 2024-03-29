//
// Created by arielpm on 25/06/19.
//

#include "CaptainAmericaGrabRightAnimation.h"

#include <SDL_timer.h>



void CaptainAmericaGrabRightAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 14;

    vector<int> frame0 = {0, 5145, 322, 245};
    vector<int> frame1 = {322, 5145, 322, 245};
    vector<int> frame2 = {644, 5145, 322, 245};
    vector<int> frame3 = {966, 5145, 322, 245};

    vector<int> frame4 = {1330, 5145, 322, 245};
    vector<int> frame5 = {1652, 5145, 322, 245};
    vector<int> frame6 = {1974, 5145, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame6);

}

CaptainAmericaGrabRightAnimation::CaptainAmericaGrabRightAnimation() : Animation() {

    this->init();

}