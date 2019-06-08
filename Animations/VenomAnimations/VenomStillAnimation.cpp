//
// Created by arielpm on 09/04/19.
//

#include "VenomStillAnimation.h"
#include <SDL_timer.h>


void VenomStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 13;

    vector<int> frame0 = {0, 0, 560, 238};
    vector<int> frame1 = {560, 0, 560, 238};
    vector<int> frame2 = {1120, 0, 560, 238};
    vector<int> frame3 = {1680, 0, 560, 238};
    vector<int> frame4 = {2240, 0, 560, 238};
    vector<int> frame5 = {2800, 0, 560, 238};
    vector<int> frame6 = {3360, 0, 560, 238};
    vector<int> frame7 = {3920, 0, 560, 238};
    vector<int> frame8 = {4480, 0, 560, 238};
    vector<int> frame9 = {5040, 0, 560, 238};
    vector<int> frame10 = {5600, 0, 560, 238};
    vector<int> frame11 = {6160, 0, 560, 238};
    vector<int> frame12 = {6720, 0, 560, 238};


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
