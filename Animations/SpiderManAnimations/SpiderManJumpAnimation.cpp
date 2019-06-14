//
// Created by arielpm on 09/04/19.
//

#include "SpiderManJumpAnimation.h"
#include <SDL_timer.h>

void SpiderManJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 25;
    animationLength = 5;

    vector<int> frame0 = {491, 1072, 491, 268};
    vector<int> frame1 = {982, 1072, 491, 268};
    vector<int> frame2 = {1473, 1072, 491, 268};
    vector<int> frame3 = {1964, 1072, 491, 268};
    vector<int> frame4 = {2455, 1072, 491, 268};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);



}

SpiderManJumpAnimation::SpiderManJumpAnimation() : Animation() {

    this->init();

}