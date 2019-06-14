//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaWalkFowardAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 20;
    animationLength = 8;

    vector<int> frame0 = {0, 250, 322, 245};
    vector<int> frame1 = {322, 250, 322, 245};
    vector<int> frame2 = {644, 250, 322, 245};
    vector<int> frame3 = {966, 250, 322, 245};
    vector<int> frame4 = {1288, 250, 322, 245};
    vector<int> frame5 = {966, 250, 322, 245};
    vector<int> frame6 = {644, 250, 322, 245};
    vector<int> frame7 = {322, 250, 322, 245};




    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

CaptainAmericaWalkFowardAnimation::CaptainAmericaWalkFowardAnimation() : Animation() {

    this->init();

}