//
// Created by trocchi on 6/1/19.
//

#include "CaptainAmericaPunchAnimation.h"

void CaptainAmericaPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 2;

    vector<int> frame1 = {98, 874, 136, 109};
    vector<int> frame2 = {98, 874, 136, 109};
//    vector<int> frame3 = {239, 878, 98, 108};

    animation.push_back(frame1);
    animation.push_back(frame2);
   // animation.push_back(frame3);

}

CaptainAmericaPunchAnimation::CaptainAmericaPunchAnimation() : Animation() {

    this->init();

}
