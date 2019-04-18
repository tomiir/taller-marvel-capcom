//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaCrowchedDownAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 2;

    //vector<int> frame0 = {5, 750, 77, 90};
    vector<int> frame1 = {102, 732, 77, 108};
    vector<int> frame2 = {205, 733, 77, 108};



    //animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaCrowchedDownAnimation::CaptainAmericaCrowchedDownAnimation() : Animation() {

    this->init();

}

