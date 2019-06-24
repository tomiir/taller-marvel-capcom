//
// Created by arielpm on 14/06/19.
//

#include "SpiderManStandKickedAnimation.h"


void SpiderManStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {982, 1340, 491, 268};

    animation.push_back(frame0);

}

SpiderManStandKickedAnimation::SpiderManStandKickedAnimation() : Animation() {

    this->init();

}