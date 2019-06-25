//
// Created by arielpm on 12/06/19.
//

#include "VenomAirGuardAnimation.h"

void VenomAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 7;

    vector<int> frame0 = {560, 1904, 560, 238};
    vector<int> frame1 = {1120, 1904, 560, 238};
    vector<int> frame2 = {1680, 1904, 560, 238};
    vector<int> frame3 = {2240, 1904, 560, 238};
    vector<int> frame4 = {2800, 1904, 560, 238};
    vector<int> frame5 = {3360, 1904, 560, 238};
    vector<int> frame6 = {3920, 1904, 560, 238};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
}

VenomAirGuardAnimation::VenomAirGuardAnimation() : Animation() {

    this->init();

}