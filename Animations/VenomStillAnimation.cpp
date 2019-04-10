//
// Created by arielpm on 09/04/19.
//

#include "VenomStillAnimation.h"
#include <SDL_timer.h>


void VenomStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 14;
    animationLength = 13;

    vector<int> frame0 = {3, 519, 134, 118};
    vector<int> frame1 = {149, 529, 142, 108};
    vector<int> frame2 = {312, 533, 152, 104};
    vector<int> frame3 = {490, 544, 153, 94};
    vector<int> frame4 = {674, 545, 154, 93};
    vector<int> frame5 = {858, 548, 152, 89};
    vector<int> frame6 = {1042, 549, 141, 89};
    vector<int> frame7 = {5, 683, 136, 88};
    vector<int> frame8 = {172, 681, 129, 89};
    vector<int> frame9 = {340, 677, 123, 94};
    vector<int> frame10 = {521, 671, 118, 100};
    vector<int> frame11 = {698, 665, 123, 105};
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
