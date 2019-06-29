//
// Created by fer on 22/06/19.
//

#include "SpiderManGrabbedAnimation.h"

#include <SDL_timer.h>



void SpiderManGrabbedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 25;
    animationLength = 9;

    vector<int> frame0 = {1964, 6184, 491, 268};
    vector<int> frame1 = {1473, 6184, 491, 268};

    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);
    animation.push_back(frame1);


}

SpiderManGrabbedAnimation::SpiderManGrabbedAnimation() : Animation() {

    this->init();

}