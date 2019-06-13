//
// Created by arielpm on 13/06/19.
//

#include "SpiderManKickedAnimation.h"


void SpiderManKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {0, 1340, 491, 268};

    animation.push_back(frame0);

}

SpiderManKickedAnimation::SpiderManKickedAnimation() : Animation() {

    this->init();

}