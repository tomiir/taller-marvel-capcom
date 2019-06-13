//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongAirPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 3;

    vector<int> frame0 = {982, 2412, 491, 268};
    vector<int> frame1 = {1473, 2412, 491, 268};
    vector<int> frame2 = {1964, 2412, 491, 268};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);



}

SpiderManStrongAirPunchAnimation::SpiderManStrongAirPunchAnimation() : Animation() {

    this->init();

}