//
// Created by arielpm on 13/06/19.
//

#include "SpiderManStrongAirPunchAnimation.h"
#include <SDL_timer.h>

void SpiderManStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 12;

    vector<int> frame0 = {0, 2412, 491, 268};
    vector<int> frame1 = {491, 2412, 491, 268};
    vector<int> frame2 = {982, 2412, 491, 268};
    vector<int> frame3 = {1473, 2412, 491, 268};
    vector<int> frame4 = {1964, 2412, 491, 268};
    vector<int> frame5 = {2455, 2412, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame5);


}

SpiderManStrongAirPunchAnimation::SpiderManStrongAirPunchAnimation() : Animation() {

    this->init();

}