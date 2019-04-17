
#include "CaptainAmericaStillAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 3;

    vector<int> frame0 = {4, 19, 87, 115};
    vector<int> frame1 = {100, 19, 89, 115};
    vector<int> frame2 = {195, 19, 90, 115};
//    vector<int> frame3 = {292, 23, 90, 109};
//    vector<int> frame4 = {389, 19, 96, 115};
//    vector<int> frame5 = {490, 19, 90, 115};
//    vector<int> frame6 = {584, 26, 88, 108};
//    vector<int> frame7 = {682, 26, 86, 108};
//    vector<int> frame8 = {778, 24, 85, 109};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
//    animation.push_back(frame3);
//    animation.push_back(frame4);
//    animation.push_back(frame5);
//    animation.push_back(frame6);
//    animation.push_back(frame7);
//    animation.push_back(frame8);

}

CaptainAmericaStillAnimation::CaptainAmericaStillAnimation() : Animation() {

    this->init();

}
