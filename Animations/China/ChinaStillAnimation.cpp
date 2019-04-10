

#include <SDL_timer.h>
#include "ChinaStillAnimation.h"

void ChinaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 8;

    vector<int> frame0 = {31, 229, 86, 86};
    vector<int> frame1 = {130, 232, 86, 87};
    vector<int> frame2 = {226, 233, 86, 87};
    vector<int> frame3 = {325, 232, 86, 88};
    vector<int> frame4 = {417, 234, 86, 87};
    vector<int> frame5 = {513, 231, 86, 87};
    vector<int> frame6 = {603, 233, 86, 87};
    vector<int> frame7 = {417, 234, 86, 87};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);

}

ChinaStillAnimation::ChinaStillAnimation() : Animation() {

    this->init();

}
