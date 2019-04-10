//
// Created by arielpm on 09/04/19.
//

#include "VenomCrowchedDownAnimation.h"
#include <SDL_timer.h>


void VenomCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 10;

    vector<int> frame0 = {6, 3584, 126, 113};
    vector<int> frame1 = {170, 3618, 112, 82};
    vector<int> frame2 = {5, 3749, 112, 85};
    vector<int> frame3 = {144, 3749, 112, 85};
    vector<int> frame4 = {284, 3749, 112, 85};
    vector<int> frame5 = {428, 3749, 112, 85};
    vector<int> frame6 = {570, 3749, 112, 85};
    vector<int> frame7 = {705, 3749, 112, 85};
    vector<int> frame8 = {842, 3749, 112, 85};
    vector<int> frame9 = {981, 3749, 112, 85};


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

VenomCrowchedDownAnimation::VenomCrowchedDownAnimation(): Animation() {

    this->init();

}