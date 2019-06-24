//
// Created by fer on 22/06/19.
//

#include "ChunLiGrabbedImpactAnimation.h"

#include <SDL_timer.h>

void ChunLiGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 5;

    vector<int> frame1 = {2035, 4620, 407, 210};
    vector<int> frame2 = {2442, 4595, 407, 210};
    vector<int> frame3 = {407, 3570, 407, 210};
    vector<int> frame4 = {0, 630, 407, 210};



    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

ChunLiGrabbedImpactAnimation::ChunLiGrabbedImpactAnimation() : Animation() {

    this->init();

}