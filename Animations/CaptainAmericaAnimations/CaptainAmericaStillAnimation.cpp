
#include "CaptainAmericaStillAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;

    vector<int> frame0 = {0, 0, 383, 212};
    vector<int> frame1 = {383, 0, 383, 212};
    vector<int> frame2 = {766, 0, 383, 212};
    vector<int> frame3 = {1149, 0, 383, 212};
    vector<int> frame4 = {1532, 0, 383, 212};
    vector<int> frame5 = {1915, 0, 383, 212};
    vector<int> frame6 = {2298, 0, 383, 212};
    vector<int> frame7 = {2681, 0, 383, 212};
    vector<int> frame8 = {3064, 0, 383, 212};



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
