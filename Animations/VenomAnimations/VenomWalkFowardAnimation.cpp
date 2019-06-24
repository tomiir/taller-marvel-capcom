//
// Created by arielpm on 09/04/19.
//

#include "VenomWalkFowardAnimation.h"
#include <SDL_timer.h>


void VenomWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 10;

    vector<int> frame0 = {0, 238, 560, 238};
    vector<int> frame1 = {560, 238, 560, 238};
    vector<int> frame2 = {1120, 238, 560, 238};
    vector<int> frame3 = {1680, 238, 560, 238};
    vector<int> frame4 = {2240, 238, 560, 238};
    vector<int> frame5 = {2800, 238, 560, 238};
    vector<int> frame6 = {3360, 238, 560, 238};
    vector<int> frame7 = {3920, 238, 560, 238};
    vector<int> frame8 = {4480, 238, 560, 238};
    vector<int> frame9 = {5040, 238, 560, 238};


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

VenomWalkFowardAnimation::VenomWalkFowardAnimation() : Animation() {

    this->init();

}
