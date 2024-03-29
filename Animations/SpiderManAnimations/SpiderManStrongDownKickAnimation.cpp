//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongDownKickAnimation.h"


void SpiderManStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 11;

    vector<int> frame0 = {0, 5360, 491, 268};
    vector<int> frame1 = {491, 5360, 491, 268};
    vector<int> frame2 = {982, 5360, 491, 268};
    vector<int> frame3 = {1473, 5360, 491, 268};
    vector<int> frame4 = {1964, 5360, 491, 268};
    vector<int> frame5 = {2455, 5360, 491, 268};
    vector<int> frame6 = {2946, 5360, 491, 268};
    vector<int> frame7 = {3437, 5360, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

SpiderManStrongDownKickAnimation::SpiderManStrongDownKickAnimation() : Animation() {

    this->init();

}