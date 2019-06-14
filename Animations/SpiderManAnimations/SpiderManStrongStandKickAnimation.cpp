//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongStandKickAnimation.h"

void SpiderManStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;

    vector<int> frame0 = {0, 4824, 491, 268};
    vector<int> frame1 = {491, 4824, 491, 268};
    vector<int> frame2 = {982, 4824, 491, 268};
    vector<int> frame3 = {1473, 4824, 491, 268};
    vector<int> frame4 = {1964, 4824, 491, 268};
    vector<int> frame5 = {2455, 4824, 491, 268};
    vector<int> frame6 = {2946, 4824, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);

}

SpiderManStrongStandKickAnimation::SpiderManStrongStandKickAnimation() : Animation() {

    this->init();

}