//
// Created by arielpm on 09/04/19.
//

#include "VenomStillAnimation.h"
#include <SDL_timer.h>


void VenomStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 13;

    vector<int> frame0 = {702, 367, 154, 118};
    vector<int> frame1 = {149, 519, 154, 118};
    vector<int> frame2 = {312, 519, 154, 118};
    vector<int> frame3 = {490, 520, 154, 118};
    vector<int> frame4 = {674, 520, 154, 118};
    vector<int> frame5 = {858, 519, 154, 118};
    vector<int> frame6 = {1042, 520, 154, 118};
    vector<int> frame7 = {909, 366, 154, 118};
    vector<int> frame8 = {172, 652, 154, 118};
    vector<int> frame9 = {340, 653, 154, 118};
    vector<int> frame10 = {521, 653, 154, 118};
    vector<int> frame11 = {698, 652, 154, 118};
    vector<int> frame12 = {879, 652, 154, 118};


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

VenomStillAnimation::VenomStillAnimation() : Animation() {

    this->init();

}
