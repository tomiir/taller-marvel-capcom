//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkBackwadsAnimation.h"
#include <SDL_timer.h>

void ChunLiWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 13;
    animationLength = 12;

    vector<int> frame0 = {30, 429, 80, 86};
    vector<int> frame1 = {120, 429, 67, 87};
    vector<int> frame2 = {207, 430, 58, 88};
    vector<int> frame3 = {273, 431, 59, 89};
    vector<int> frame4 = {340, 434, 62, 88};
    vector<int> frame5 = {411, 435, 64, 87};
    vector<int> frame6 = {485, 437, 70, 86};
    vector<int> frame7 = {567, 435, 64, 87};
    vector<int> frame8 = {638, 434, 62, 88};
    vector<int> frame9 = {712, 435, 59, 89};
    vector<int> frame10 = {780, 436, 58, 88};
    vector<int> frame11 = {843, 435, 67, 87};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame9);
    animation.push_back(frame10);
    animation.push_back(frame11);


}

ChunLiWalkBackwardsAnimation::ChunLiWalkBackwardsAnimation() : Animation() {

    this->init();

}