//
// Created by fer on 22/06/19.
//

#include "SpiderManGrabbedImpactAnimation.h"

#include <SDL_timer.h>



void SpiderManGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 5;

    vector<int> frame0 = {982, 6164, 491, 268};
    vector<int> frame1 = {491, 6144, 491, 268};
    vector<int> frame2 = {0, 6144, 491, 268};
    vector<int> frame3 = {0, 2680, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

SpiderManGrabbedImpactAnimation::SpiderManGrabbedImpactAnimation() : Animation() {

    this->init();

}