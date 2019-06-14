//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongStandPunchAnimation.h"

void VenomStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 10;

    vector<int> frame0 = {0, 2618, 560, 238};
    vector<int> frame1 = {560, 2618, 560, 238};
    vector<int> frame2 = {1120, 2618, 560, 238};
    vector<int> frame3 = {1120, 2618, 560, 238};
    vector<int> frame4 = {1680, 2618, 560, 238};
    vector<int> frame5 = {1680, 2618, 560, 238};
    vector<int> frame6 = {2240, 2618, 560, 238};
    vector<int> frame7 = {2240, 2618, 560, 238};
    vector<int> frame8 = {2800, 2618, 560, 238};
    vector<int> frame9 = {3360, 2618, 560, 238};


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

VenomStrongStandPunchAnimation::VenomStrongStandPunchAnimation() : Animation() {

    this->init();

}