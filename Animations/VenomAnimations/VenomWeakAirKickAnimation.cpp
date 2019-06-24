//
// Created by arielpm on 14/06/19.
//

#include "VenomWeakAirKickAnimation.h"


void VenomWeakAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 9;

    vector<int> frame0 = {0, 3808, 560, 238};
    vector<int> frame1 = {560, 3808, 560, 238};
    vector<int> frame2 = {560, 3808, 560, 238};
    vector<int> frame3 = {560, 3808, 560, 238};
    vector<int> frame4 = {560, 3808, 560, 238};
    vector<int> frame5 = {560, 3808, 560, 238};
    vector<int> frame6 = {560, 3808, 560, 238};
    vector<int> frame7 = {560, 3808, 560, 238};
    vector<int> frame8 = {1120, 3808, 560, 238};

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

VenomWeakAirKickAnimation::VenomWeakAirKickAnimation() : Animation() {

    this->init();

}