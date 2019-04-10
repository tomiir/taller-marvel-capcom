

#include <SDL_timer.h>
#include "CaptainAmericaStillAnimation.h"

void ChinaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 5;

    vector<int> frame0 = {4, 19, 87, 115};
    vector<int> frame1 = {100, 19, 89, 115};
    vector<int> frame2 = {195, 19, 90, 115};
    vector<int> frame3 = {389, 19, 96, 115};
    vector<int> frame4 = {490, 19, 90, 115};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);

}

ChinaStillAnimation::ChinaStillAnimation() : Animation() {

    this->init();

}
