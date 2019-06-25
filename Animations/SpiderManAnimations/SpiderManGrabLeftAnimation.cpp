//
// Created by arielpm on 13/06/19.
//

#include "SpiderManGrabLeftAnimation.h"
#include <SDL_timer.h>

void SpiderManGrabLeftAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 9;

    vector<int> frame0 = {0, 5628, 491, 268};
    vector<int> frame1 = {491, 5628, 491, 268};
    vector<int> frame2 = {982, 5628, 491, 268};
    vector<int> frame3 = {1473, 5628, 491, 268};
    vector<int> frame4 = {1964, 5628, 491, 268};
    vector<int> frame5 = {2455, 5628, 491, 268};
    vector<int> frame6 = {2946, 5628, 491, 268};
    vector<int> frame7 = {3437, 5628, 491, 268};
    vector<int> frame8 = {3928, 5628, 491, 268};



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

SpiderManGrabLeftAnimation::SpiderManGrabLeftAnimation() : Animation() {

    this->init();

}