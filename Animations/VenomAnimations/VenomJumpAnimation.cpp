//
// Created by arielpm on 09/04/19.
//

#include "VenomJumpAnimation.h"
#include <SDL_timer.h>


void VenomJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 8;

    //vector<int> frame0 = {4, 5480, 129, 88};
    vector<int> frame1 = {206, 5415, 133, 153};
    vector<int> frame2 = {354, 5406, 127, 162};
    vector<int> frame3 = {558, 5424, 153, 111};
    vector<int> frame4 = {725, 5421, 133, 103};
    vector<int> frame5 = {877, 5421, 115, 85};
    vector<int> frame6 = {1011, 5422, 133, 103};
    vector<int> frame7 = {3, 5588, 131, 136};
    vector<int> frame8 = {148, 5581, 130, 144};
    //vector<int> frame9 = {444, 5637, 129, 88};
    //vector<int> frame10 = {597, 5645, 112, 82};


    //animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    //animation.push_back(frame9);
    //animation.push_back(frame10);

}

VenomJumpAnimation::VenomJumpAnimation() : Animation() {

    this->init();

}