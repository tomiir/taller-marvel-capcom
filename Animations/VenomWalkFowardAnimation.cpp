//
// Created by arielpm on 09/04/19.
//

#include "VenomWalkFowardAnimation.h"
#include <SDL_timer.h>


void VenomWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 10;

    vector<int> frame0 = {7, 2918, 148, 112};
    vector<int> frame1 = {186, 2916, 134, 113};
    vector<int> frame2 = {348, 2915, 120, 111};
    vector<int> frame3 = {495, 2914, 97, 111};
    vector<int> frame4 = {614, 2913, 126, 112};
    vector<int> frame5 = {769, 2915, 149, 113};
    vector<int> frame6 = {942, 2913, 130, 115};
    vector<int> frame7 = {1096, 2912, 98, 116};
    vector<int> frame8 = {7, 3043, 104, 115};
    vector<int> frame9 = {143, 3045, 129, 113};


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
