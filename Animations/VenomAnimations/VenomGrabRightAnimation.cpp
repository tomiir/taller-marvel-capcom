//
// Created by arielpm on 25/06/19.
//

#include "VenomGrabRightAnimation.h"
#include <SDL_timer.h>


void VenomGrabRightAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 10;

    vector<int> frame0 = {0, 4998, 560, 238};
    vector<int> frame1 = {560, 4998, 560, 238};
    vector<int> frame2 = {1120, 4998, 560, 238};
    vector<int> frame3 = {1680, 4998, 560, 238};
    vector<int> frame4 = {2240, 4998, 560, 238};
    vector<int> frame5 = {2800, 4998, 560, 238};
    vector<int> frame6 = {3360, 4998, 560, 238};
    vector<int> frame7 = {3920, 4998, 560, 238};
    vector<int> frame8 = {4480, 4998, 560, 238};
    vector<int> frame9 = {5040, 4998, 560, 238};


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

VenomGrabRightAnimation::VenomGrabRightAnimation() : Animation() {

    this->init();

}