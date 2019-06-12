//
// Created by arielpm on 12/06/19.
//

#include "VenomStronDownPunchAnimation.h"

void VenomStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 7;

    vector<int> frame0 = {0, 2380, 560, 238};
    vector<int> frame1 = {560, 2380, 560, 238};
    vector<int> frame2 = {1120, 2380, 560, 238};
    vector<int> frame3 = {1680, 2380, 560, 238};
    vector<int> frame4 = {2240, 2380, 560, 238};
    vector<int> frame5 = {2800, 2380, 560, 238};
    vector<int> frame6 = {3360, 2380, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);

}

VenomStrongDownPunchAnimation::VenomStrongDownPunchAnimation() : Animation() {

    this->init();

}