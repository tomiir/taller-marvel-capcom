//
// Created by arielpm on 13/06/19.
//

#include "SpiderManDownKickedAnimation.h"


void SpiderManDownKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {0, 1340, 491, 268};

    animation.push_back(frame0);

}

SpiderManDownKickedAnimation::SpiderManDownKickedAnimation() : Animation() {

    this->init();

}