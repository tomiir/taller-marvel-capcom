//
// Created by arielpm on 09/04/19.
//

#include "VenomCrowchedDownAnimation.h"
#include <SDL_timer.h>


void VenomCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 8;

    vector<int> frame0 = {0, 714, 560, 238};
    vector<int> frame1 = {560, 714, 560, 238};
    vector<int> frame2 = {1120, 714, 560, 238};
    vector<int> frame3 = {1680, 714, 560, 238};
    vector<int> frame4 = {2240, 714, 560, 238};
    vector<int> frame5 = {2800, 714, 560, 238};
    vector<int> frame6 = {3360, 714, 560, 238};
    vector<int> frame7 = {3920, 714, 560, 238};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

VenomCrowchedDownAnimation::VenomCrowchedDownAnimation(): Animation() {

    this->init();

}