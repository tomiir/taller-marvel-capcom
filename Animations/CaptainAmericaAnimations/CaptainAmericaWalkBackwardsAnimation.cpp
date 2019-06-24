

#include "CaptainAmericaWalkBackwardsAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;

    vector<int> frame0 = {0, 490, 322, 245};
    vector<int> frame1 = {322, 490, 322, 245};
    vector<int> frame2 = {644, 490, 322, 245};
    vector<int> frame3 = {966, 490, 322, 245};
    vector<int> frame4 = {1288, 490, 322, 245};
    vector<int> frame5 = {1610, 490, 322, 245};
    vector<int> frame6 = {1932, 490, 322, 245};



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