//
// Created by arielpm on 13/06/19.
//

#include "ChunLiGrabLeftAnimation.h"
#include <SDL_timer.h>

void ChunLiGrabLeftAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 4;

    vector<int> frame0 = {0, 4410, 407, 210};
    vector<int> frame1 = {407, 4410, 407, 210};
    vector<int> frame2 = {814, 4410, 407, 210};
    vector<int> frame3 = {1221, 4410, 407, 210};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
}

ChunLiGrabLeftAnimation::ChunLiGrabLeftAnimation() : Animation() {

    this->init();

}