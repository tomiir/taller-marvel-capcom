//
// Created by arielpm on 12/06/19.
//

#include "VenomWeakAirPunchAnimation.h"


void VenomWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 8;

    vector<int> frame0 = {0, 2856, 560, 238};
    vector<int> frame1 = {560, 2856, 560, 238};
    vector<int> frame2 = {560, 2856, 560, 238};
    vector<int> frame3 = {560, 2856, 560, 238};
    vector<int> frame4 = {560, 2856, 560, 238};
    vector<int> frame5 = {560, 2856, 560, 238};
    vector<int> frame6 = {560, 2856, 560, 238};
    vector<int> frame7 = {1120, 2856, 560, 238};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

VenomWeakAirPunchAnimation::VenomWeakAirPunchAnimation() : Animation() {

    this->init();

}