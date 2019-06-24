//
// Created by fer on 22/06/19.
//

#include "ChunLiGrabbedAnimation.h"

#include <SDL_timer.h>

void ChunLiGrabbedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 4;

    vector<int> frame0 = {0, 4620, 407, 210};
    vector<int> frame1 = {407, 4620, 407, 210};
    vector<int> frame2 = {814, 4620, 407, 210};
    vector<int> frame3 = {1221, 4620, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
}

ChunLiGrabbedAnimation::ChunLiGrabbedAnimation() : Animation() {

    this->init();

}