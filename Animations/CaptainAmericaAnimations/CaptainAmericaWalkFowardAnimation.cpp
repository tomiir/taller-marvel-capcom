//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaWalkFowardAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 5;

    vector<int> frame0 = {0, 212, 383, 212};
    vector<int> frame1 = {383, 212, 383, 212};
    vector<int> frame2 = {766, 212, 383, 212};
    vector<int> frame3 = {1149, 212, 383, 212};
    vector<int> frame4 = {1532, 212, 383, 212};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);


}

CaptainAmericaWalkFowardAnimation::CaptainAmericaWalkFowardAnimation() : Animation() {

    this->init();

}