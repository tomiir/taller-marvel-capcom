//
// Created by arielpm on 09/04/19.
//

#include "SpiderManCrowchedDownAnimation.h"
#include <SDL_timer.h>

void SpiderManCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;

    vector<int> frame0 = {0, 804, 491, 268};

    animation.push_back(frame0);


}

SpiderManCrowchedDownAnimation::SpiderManCrowchedDownAnimation() : Animation() {

    this->init();

}