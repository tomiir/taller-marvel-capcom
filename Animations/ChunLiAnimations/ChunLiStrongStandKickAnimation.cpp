//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongStandKickAnimation.h"

void ChunLiStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 10;

    vector<int> frame0 = {0, 3780, 407, 210};
    vector<int> frame1 = {407, 3780, 407, 210};
    vector<int> frame2 = {814, 3780, 407, 210};
    vector<int> frame3 = {1221, 3780, 407, 210};
    vector<int> frame4 = {1628, 3780, 407, 210};
    vector<int> frame5 = {2035, 3780, 407, 210};
    vector<int> frame6 = {2442, 3780, 407, 210};
    vector<int> frame7 = {2849, 3780, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame7);
    animation.push_back(frame7);

}

ChunLiStrongStandKickAnimation::ChunLiStrongStandKickAnimation() : Animation() {

    this->init();

}