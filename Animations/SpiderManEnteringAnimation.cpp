//
// Created by arielpm on 13/04/19.
//

#include "SpiderManEnteringAnimation.h"
#include <SDL_timer.h>

void SpiderManEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 2;

    vector<int> frame0 = {1367, 4298, 73, 139};
    vector<int> frame1 = {1452, 4292, 65, 144};


    animation.push_back(frame0);
    animation.push_back(frame1);



}

SpiderManEnteringAnimation::SpiderManEnteringAnimation() : Animation() {

    this->init();

}