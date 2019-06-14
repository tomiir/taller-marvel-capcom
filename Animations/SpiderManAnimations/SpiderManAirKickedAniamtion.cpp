//
// Created by arielpm on 14/06/19.
//

#include "SpiderManAirKickedAniamtion.h"


void SpiderManAirKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;



    vector<int> frame0 = {491, 1340, 491, 268};

    animation.push_back(frame0);

}

SpiderManAirKickedAnimation::SpiderManAirKickedAnimation() : Animation() {

    this->init();

}