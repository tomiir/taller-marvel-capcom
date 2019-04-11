//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaCrowchedDownAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 3;

    vector<int> frame0 = {5, 750, 77, 90};
    vector<int> frame1 = {102, 762, 77, 78};
    vector<int> frame2 = {205, 763, 77, 78};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaCrowchedDownAnimation::CaptainAmericaCrowchedDownAnimation() : Animation() {

    this->init();

}

