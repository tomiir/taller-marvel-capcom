

#include "CaptainAmericaWalkBackwardsAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 6;

    vector<int> frame0 = {4, 292, 99, 117};
    vector<int> frame1 = {113, 289, 70, 116};
    vector<int> frame2 = {198, 291, 85, 117};
    vector<int> frame3 = {296, 293, 103, 117};
    vector<int> frame4 = {415, 293, 69, 119};
    vector<int> frame5 = {500, 296, 84, 117};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);


}

CaptainAmericaWalkBackwardsAnimation::CaptainAmericaWalkBackwardsAnimation() : Animation() {

    this->init();

}