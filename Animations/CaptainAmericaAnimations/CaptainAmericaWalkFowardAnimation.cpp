//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaWalkFowardAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 6;

    vector<int> frame0 = {0, 163, 97, 114};
    vector<int> frame1 = {99, 160, 97,116};
    vector<int> frame2 = {196, 162, 97, 114};
    vector<int> frame3 = {300, 161, 97, 111};
    vector<int> frame4 = {402, 160, 97, 113};
    vector<int> frame5 = {504, 161, 95, 114};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);


}

CaptainAmericaWalkFowardAnimation::CaptainAmericaWalkFowardAnimation() : Animation() {

    this->init();

}