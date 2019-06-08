//
// Created by arielpm on 13/04/19.
//

#include "SpiderManEnteringAnimation.h"
#include <SDL_timer.h>

void SpiderManEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 2;

    vector<int> frame0 = {3437, 5896, 491, 268};
    vector<int> frame1 = {3928, 5896, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);



}

SpiderManEnteringAnimation::SpiderManEnteringAnimation() : Animation() {

    this->init();

}