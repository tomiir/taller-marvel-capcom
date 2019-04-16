//
// Created by arielpm on 09/04/19.
//

#include "VenomWalkBackwardsAnimation.h"
#include <SDL_timer.h>


void VenomWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 10;

    vector<int> frame0 = {6, 3252, 125, 120};
    vector<int> frame1 = {164, 3249, 108, 123};
    vector<int> frame2 = {305, 3248, 102, 124};
    vector<int> frame3 = {441, 3250, 122, 122};
    vector<int> frame4 = {596, 3252, 138, 120};
    vector<int> frame5 = {761, 3250, 118, 119};
    vector<int> frame6 = {913, 3250, 91, 119};
    vector<int> frame7 = {1033, 3251, 116, 119};
    vector<int> frame8 = {8, 3393, 130, 120};
    vector<int> frame9 = {165, 3388, 138, 121};


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

VenomWalkBackwardsAnimation::VenomWalkBackwardsAnimation(): Animation() {

    this->init();

}