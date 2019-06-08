//
// Created by arielpm on 09/04/19.
//

#include "SpiderManStillAnimation.h"
#include <SDL_timer.h>

void SpiderManStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 9;

    vector<int> frame0 = {0, 0, 491, 268};
    vector<int> frame1 = {491, 0, 491, 268};
    vector<int> frame2 = {982, 0, 491, 268};
    vector<int> frame3 = {1473, 0, 491, 268};
    vector<int> frame4 = {1964, 0, 491, 268};
    vector<int> frame5 = {2455, 0, 491, 268};
    vector<int> frame6 = {2946, 0, 491, 268};
    vector<int> frame7 = {3437, 0, 491, 268};
    vector<int> frame8 = {3828, 0, 491, 268};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);


}

SpiderManStillAnimation::SpiderManStillAnimation() : Animation() {

    this->init();

}