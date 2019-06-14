//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongDownKickAnimation.h"


void VenomStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 9;

    vector<int> frame0 = {0, 4760, 560, 238};
    vector<int> frame1 = {560, 4760, 560, 238};
    vector<int> frame2 = {1120, 4760, 560, 238};
    vector<int> frame3 = {1120, 4760, 560, 238};
    vector<int> frame4 = {1120, 4760, 560, 238};
    vector<int> frame5 = {1120, 4760, 560, 238};
    vector<int> frame6 = {1120, 4760, 560, 238};
    vector<int> frame7 = {1120, 4760, 560, 238};
    vector<int> frame8 = {1680, 4760, 560, 238};


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

VenomStrongDownKickAnimation::VenomStrongDownKickAnimation() : Animation() {

    this->init();

}