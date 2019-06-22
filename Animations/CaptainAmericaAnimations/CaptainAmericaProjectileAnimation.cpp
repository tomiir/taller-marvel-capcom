//
// Created by arielpm on 22/06/19.
//

#include "CaptainAmericaProjectileAnimation.h"

#include <SDL_timer.h>

void CaptainAmericaProjectileAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 5;

    vector<int> frame0 = {0, 0, 322, 245};
    vector<int> frame1 = {322, 0, 322, 245};
    vector<int> frame2 = {644, 0, 322, 245};
    vector<int> frame3 = {966, 0, 322, 245};
    vector<int> frame4 = {1288, 0, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

CaptainAmericaProjectileAnimation::CaptainAmericaProjectileAnimation() : Animation() {

    this->init();

}