//
// Created by arielpm on 13/04/19.
//

#include "ChunLiEnteringAnimation.h"
#include <SDL_timer.h>

void ChunLiEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;


    vector<int> frame0 = {514, 535, 50, 94};
    vector<int> frame1 = {579, 539, 42, 107};
    vector<int> frame2 = {633, 539, 54, 107};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);


}

ChunLiEnteringAnimation::ChunLiEnteringAnimation() : Animation() {

    this->init();
}