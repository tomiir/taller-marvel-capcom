//
// Created by fer on 01/06/19.
//

#include "VenomWeakStandPunchAnimation.h"

void VenomWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 9;

    vector<int> frame0 = {0, 3332, 560, 238};
    vector<int> frame1 = {560, 3332, 560, 238};
    vector<int> frame2 = {560, 3332, 560, 238};
    vector<int> frame3 = {560, 3332, 560, 238};
    vector<int> frame4 = {560, 3332, 560, 238};
    vector<int> frame5 = {560, 3332, 560, 238};
    vector<int> frame6 = {560, 3332, 560, 238};
    vector<int> frame7 = {560, 3332, 560, 238};
    vector<int> frame8 = {560, 3332, 560, 238};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);

}

VenomWeakStandPunchAnimation::VenomWeakStandPunchAnimation() : Animation() {

    this->init();

}