//
// Created by arielpm on 13/06/19.
//

#include "SpiderManGrabLeftAnimation.h"
#include <SDL_timer.h>

void SpiderManGrabLeftAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 17;

    vector<int> frame0 = {0, 5628, 491, 268};
    vector<int> frame1 = {491, 5628, 491, 268};
    vector<int> frame2 = {982, 5628, 491, 268};
    vector<int> frame3 = {1473, 5628, 491, 268};

    vector<int> frame4 = {1984, 5628, 491, 268};
    vector<int> frame5 = {2475, 5628, 491, 268};
    vector<int> frame6 = {2966, 5628, 491, 268};
    vector<int> frame7 = {3457, 5628, 491, 268};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame6);
    animation.push_back(frame7);




}

SpiderManGrabLeftAnimation::SpiderManGrabLeftAnimation() : Animation() {

    this->init();

}