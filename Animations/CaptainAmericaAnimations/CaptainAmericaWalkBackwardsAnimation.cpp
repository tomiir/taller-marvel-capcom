

#include "CaptainAmericaWalkBackwardsAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;

    vector<int> frame0 = {0, 424, 383, 212};
    vector<int> frame1 = {383, 424, 383, 212};
    vector<int> frame2 = {766, 424, 383, 212};
    vector<int> frame3 = {1149, 424, 383, 212};
    vector<int> frame4 = {1532, 424, 383, 212};
    vector<int> frame5 = {1915, 424, 383, 212};
    vector<int> frame6 = {2298, 424, 383, 212};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);


}

CaptainAmericaWalkBackwardsAnimation::CaptainAmericaWalkBackwardsAnimation() : Animation() {

    this->init();

}