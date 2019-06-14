//
// Created by arielpm on 13/06/19.
//

#include "ChunLiStrongDownKickAnimation.h"

void ChunLiStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 9;

    vector<int> frame0 = {0, 4200, 407, 210};
    vector<int> frame1 = {407, 4200, 407, 210};
    vector<int> frame2 = {814, 4200, 407, 210};
    vector<int> frame3 = {1221, 4200, 407, 210};
    vector<int> frame4 = {1628, 4200, 407, 210};
    vector<int> frame5 = {2035, 4200, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
}

ChunLiStrongDownKickAnimation::ChunLiStrongDownKickAnimation() : Animation() {

    this->init();

}