//
// Created by arielpm on 21/06/19.
//

#include "ChunLiThrowAnimation.h"
#include <SDL_timer.h>

void ChunLiThrowAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 3;

    vector<int> frame0 = {0, 4830, 407, 210};
    vector<int> frame1 = {407, 4830, 407, 210};
    vector<int> frame2 = {814, 4830, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

ChunLiThrowAnimation::ChunLiThrowAnimation() : Animation() {

    this->init();
}