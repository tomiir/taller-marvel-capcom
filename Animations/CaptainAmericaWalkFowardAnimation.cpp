//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaWalkFowardAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 6;

    vector<int> frame0 = {9, 163, 78, 114};
    vector<int> frame1 = {118, 160, 59,116};
    vector<int> frame2 = {196, 162, 97, 114};
    vector<int> frame3 = {307, 161, 79, 111};
    vector<int> frame4 = {421, 160, 58, 113};
    vector<int> frame5 = {506, 161, 92, 114};


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