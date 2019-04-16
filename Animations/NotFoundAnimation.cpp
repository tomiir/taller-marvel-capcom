//
// Created by feeer on 15/4/2019.
//

#include <SDL_timer.h>
#include "NotFoundAnimation.h"

void NotFoundAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    vector<int> frame = {0,0,50,100};

    animation.push_back(frame);
}

NotFoundAnimation::NotFoundAnimation() : Animation() {

    this->init();

}