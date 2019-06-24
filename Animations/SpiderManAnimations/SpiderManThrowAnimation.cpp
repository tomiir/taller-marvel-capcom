//
// Created by arielpm on 21/06/19.
//

#include "SpiderManThrowAnimation.h"
#include <SDL_timer.h>

void SpiderManThrowAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 4;

    vector<int> frame0 = {0, 6432, 491, 268};
    vector<int> frame1 = {491, 6432, 491, 268};
    vector<int> frame2 = {982, 6432, 491, 268};
    vector<int> frame3 = {1473, 6432, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManThrowAnimation::SpiderManThrowAnimation() : Animation() {

    this->init();

}