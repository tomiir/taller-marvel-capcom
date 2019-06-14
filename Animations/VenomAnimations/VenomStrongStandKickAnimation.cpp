//
// Created by arielpm on 12/06/19.
//

#include "VenomStrongStandKickAnimation.h"


void VenomStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 13;


    vector<int> frame0 = {0, 4284, 560, 238};
    vector<int> frame1 = {560, 4284, 560, 238};
    vector<int> frame2 = {1120, 4284, 560, 238};
    vector<int> frame3 = {1680, 4284, 560, 238};
    vector<int> frame4 = {1680, 4284, 560, 238};
    vector<int> frame5 = {1680, 4284, 560, 238};
    vector<int> frame6 = {2240, 4284, 560, 238};
    vector<int> frame7 = {2240, 4284, 560, 238};
    vector<int> frame8 = {2240, 4284, 560, 238};
    vector<int> frame9 = {2800, 4284, 560, 238};
    vector<int> frame10 = {3360, 4284, 560, 238};
    vector<int> frame11 = {3920, 4284, 560, 238};
    vector<int> frame12 = {4480, 4284, 560, 238};


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

VenomStrongStandKickAnimation::VenomStrongStandKickAnimation() : Animation() {

    this->init();

}