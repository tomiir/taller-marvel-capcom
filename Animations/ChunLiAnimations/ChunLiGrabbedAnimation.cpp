//
// Created by fer on 22/06/19.
//

#include "ChunLiGrabbedAnimation.h"

#include <SDL_timer.h>

void ChunLiGrabbedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 17;
    animationLength = 10;

    vector<int> frame0 = {0, 4650, 407, 210};
    vector<int> frame1 = {407, 4650, 407, 210};
    vector<int> frame2 = {814, 4650, 407, 210};
    vector<int> frame3 = {1221, 4650, 407, 210};
    vector<int> frame4 = {1628, 4650, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
}

ChunLiGrabbedAnimation::ChunLiGrabbedAnimation() : Animation() {

    this->init();

}