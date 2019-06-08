//
// Created by arielpm on 09/04/19.
//

#include "VenomJumpAnimation.h"
#include <SDL_timer.h>


void VenomJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 8;

    vector<int> frame0 = {0, 952, 560, 238};
    vector<int> frame1 = {560, 952, 560, 238};
    vector<int> frame2 = {1120, 952, 560, 238};
    vector<int> frame3 = {1680, 952, 560, 238};
    vector<int> frame4 = {2240, 952, 560, 238};
    vector<int> frame5 = {2800, 952, 560, 238};
    vector<int> frame6 = {3360, 952, 560, 238};
    vector<int> frame7 = {3920, 952, 560, 238};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

VenomJumpAnimation::VenomJumpAnimation() : Animation() {

    this->init();

}