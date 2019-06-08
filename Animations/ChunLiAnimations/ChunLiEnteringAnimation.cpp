//
// Created by arielpm on 13/04/19.
//

#include "ChunLiEnteringAnimation.h"
#include <SDL_timer.h>

void ChunLiEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;


    vector<int> frame0 = {0, 840, 407, 210};
    vector<int> frame1 = {407, 840, 407, 210};
    vector<int> frame2 = {814, 840, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);


}

ChunLiEnteringAnimation::ChunLiEnteringAnimation() : Animation() {

    this->init();
}