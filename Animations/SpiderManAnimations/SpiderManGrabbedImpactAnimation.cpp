//
// Created by fer on 22/06/19.
//

#include "SpiderManGrabbedImpactAnimation.h"

#include <SDL_timer.h>



void SpiderManGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 3;

    vector<int> frame0 = {982, 6164, 491, 268};
    vector<int> frame1 = {1473, 6164, 491, 268};
    vector<int> frame2 = {1964, 6164, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

SpiderManGrabbedImpactAnimation::SpiderManGrabbedImpactAnimation() : Animation() {

    this->init();

}