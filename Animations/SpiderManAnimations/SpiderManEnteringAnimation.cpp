//
// Created by arielpm on 13/04/19.
//

#include "SpiderManEnteringAnimation.h"
#include <SDL_timer.h>

void SpiderManEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 15;
    animationLength = 10;

    vector<int> frame0 = {3437, 5896, 491, 268};
    vector<int> frame1 = {3437, 5896, 491, 268};
    vector<int> frame2 = {3437, 5896, 491, 268};
    vector<int> frame3 = {3437, 5896, 491, 268};
    vector<int> frame4 = {3928, 5896, 491, 268};
    vector<int> frame5 = {3928, 5896, 491, 268};
    vector<int> frame6 = {3928, 5896, 491, 268};
    vector<int> frame7 = {3928, 5896, 491, 268};
    vector<int> frame8 = {4419, 5896, 491, 268};
    vector<int> frame9 = {4910, 5896, 491, 268};



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

SpiderManEnteringAnimation::SpiderManEnteringAnimation() : Animation() {

    this->init();

}