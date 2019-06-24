//
// Created by fer on 22/06/19.
//

#include "CaptainAmericaGrabbedImpactAnimation.h"


#include "CaptainAmericaGrabbedImpactAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaGrabbedImpactAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 5;

    vector<int> frame0 = {966, 5390, 322, 245};
    vector<int> frame1 = {1288, 5390, 322, 245};
    vector<int> frame2 = {644, 4165, 322, 245};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);

}

CaptainAmericaGrabbedImpactAnimation::CaptainAmericaGrabbedImpactAnimation() : Animation() {

    this->init();

}