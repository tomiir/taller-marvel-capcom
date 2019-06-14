//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongStandKickAnimation.h"


void VenomStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;


    vector<int> frame0 = {0, 4284, 560, 238};
    vector<int> frame1 = {560, 4284, 560, 238};
    vector<int> frame2 = {1120, 4284, 560, 238};
    vector<int> frame3 = {1680, 4284, 560, 238};
    vector<int> frame4 = {2240, 4284, 560, 238};
    vector<int> frame5 = {2800, 4284, 560, 238};
    vector<int> frame6 = {3360, 4284, 560, 238};
    vector<int> frame7 = {3920, 4284, 560, 238};
    vector<int> frame8 = {4480, 4284, 560, 238};


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

VenomStrongStandKickAnimation::VenomStrongStandKickAnimation() : Animation() {

    this->init();

}