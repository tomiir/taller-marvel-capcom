//
// Created by arielpm on 09/04/19.
//

#include "SpiderManWalkAnimation.h"
#include <SDL_timer.h>

void SpiderManWalkAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 12;

    vector<int> frame0 = {0, 268, 491, 268};
    vector<int> frame1 = {491, 268, 491, 268};
    vector<int> frame2 = {982, 268, 491, 268};
    vector<int> frame3 = {1473, 268, 491, 268};
    vector<int> frame4 = {1964, 268, 491, 268};
    vector<int> frame5 = {2455, 268, 491, 268};
    vector<int> frame6 = {2946, 268, 491, 268};
    vector<int> frame7 = {3437, 268, 491, 268};
    vector<int> frame8 = {3928, 268, 491, 268};
    vector<int> frame9 = {4419, 268, 491, 268};
    vector<int> frame10 = {4910, 268, 491, 268};
    vector<int> frame11 = {5401, 268, 491, 268};



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

SpiderManWalkAnimation::SpiderManWalkAnimation() : Animation() {

    this->init();

}