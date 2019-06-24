//
// Created by arielpm on 22/06/19.
//

#include "SpiderManProjectileAnimation.h"

#include <SDL_timer.h>

void SpiderManProjectileAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 4;

    vector<int> frame0 = {0, 0, 491, 268};
    vector<int> frame1 = {491, 0, 491, 268};
    vector<int> frame2 = {982, 0, 491, 268};
    vector<int> frame3 = {1473, 0, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManProjectileAnimation::SpiderManProjectileAnimation() : Animation() {

    this->init();

}