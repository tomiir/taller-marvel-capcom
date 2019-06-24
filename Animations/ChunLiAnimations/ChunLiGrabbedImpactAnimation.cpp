//
// Created by fer on 22/06/19.
//

#include "ChunLiGrabbedImpactAnimation.h"

#include <SDL_timer.h>

void ChunLiGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 20;
    animationLength = 3;

    vector<int> frame0 = {1628, 4620, 407, 210};
    vector<int> frame1 = {2035, 4620, 407, 210};
    vector<int> frame2 = {2442, 4620, 407, 210};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
}

ChunLiGrabbedImpactAnimation::ChunLiGrabbedImpactAnimation() : Animation() {

    this->init();

}