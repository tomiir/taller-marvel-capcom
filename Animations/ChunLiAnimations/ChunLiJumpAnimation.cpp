//
// Created by arielpm on 13/04/19.
//

#include "ChunLiJumpAnimation.h"
#include <SDL_timer.h>

void ChunLiJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 10;

    vector<int> frame0 = {1, 541, 85, 79};
    vector<int> frame1 = {106, 528, 41, 104};
    vector<int> frame2 = {167, 527, 46, 89};
    vector<int> frame3 = {227, 529, 52, 74};
    vector<int> frame4 = {294, 540, 57, 57};
    vector<int> frame5 = {365, 539, 59, 59};
    vector<int> frame6 = {436, 536, 58, 79};
    vector<int> frame7 = {514, 535, 50, 94};
    vector<int> frame8 = {579, 539, 42, 107};
    vector<int> frame9 = {633, 539, 54, 107};


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


}

ChunLiJumpAnimation::ChunLiJumpAnimation() : Animation() {

    this->init();
}