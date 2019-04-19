//
// Created by arielpm on 09/04/19.
//

#include "VenomCrowchedDownAnimation.h"
#include <SDL_timer.h>


void VenomCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 8;

    //vector<int> frame0 = {6, 3584, 126, 113};
    //vector<int> frame1 = {170, 3585, 112, 115};
    vector<int> frame2 = {5, 3719, 112, 115};
    vector<int> frame3 = {144, 3719, 112, 115};
    vector<int> frame4 = {284, 3719, 112, 115};
    vector<int> frame5 = {428, 3719, 112, 115};
    vector<int> frame6 = {570, 3719, 112, 115};
    vector<int> frame7 = {705, 3719, 112, 115};
    vector<int> frame8 = {842, 3719, 112, 115};
    vector<int> frame9 = {981, 3719, 112, 115};


    //animation.push_back(frame0);
    //animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame9);

}

VenomCrowchedDownAnimation::VenomCrowchedDownAnimation(): Animation() {

    this->init();

}