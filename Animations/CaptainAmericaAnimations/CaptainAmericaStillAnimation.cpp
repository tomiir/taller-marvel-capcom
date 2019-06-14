
#include "CaptainAmericaStillAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 15;
    animationLength = 9;

    vector<int> frame0 = {0, 0, 322, 245};
    vector<int> frame1 = {322, 0, 322, 245};
    vector<int> frame2 = {644, 0, 322, 245};
    vector<int> frame3 = {966, 0, 322, 245};
    vector<int> frame4 = {1288, 0, 322, 245};
    vector<int> frame5 = {1610, 0, 322, 245};
    vector<int> frame6 = {1932, 0, 322, 245};
    vector<int> frame7 = {2254, 0, 322, 245};
    vector<int> frame8 = {2576, 0, 322, 245};



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

CaptainAmericaStillAnimation::CaptainAmericaStillAnimation() : Animation() {

    this->init();

}
