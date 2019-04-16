//
// Created by arielpm on 09/04/19.
//

#include "VenomStillAnimation.h"
#include <SDL_timer.h>


void VenomStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 13;

    vector<int> frame0 = {3, 519, 134, 118};
    vector<int> frame1 = {149, 523, 142, 114};
    vector<int> frame2 = {312, 526, 152, 111};
    vector<int> frame3 = {490, 527, 153, 111};
    vector<int> frame4 = {674, 527, 154, 111};
    vector<int> frame5 = {858, 527, 152, 110};
    vector<int> frame6 = {1042, 528, 141, 110};
    vector<int> frame7 = {5, 663, 136, 108};
    vector<int> frame8 = {172, 662, 129, 108};
    vector<int> frame9 = {340, 661, 123, 110};
    vector<int> frame10 = {521, 661, 118, 110};
    vector<int> frame11 = {698, 660, 123, 110};
    vector<int> frame12 = {879, 658, 129, 112};


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
