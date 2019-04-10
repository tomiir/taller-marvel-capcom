//
// Created by arielpm on 09/04/19.
//

#include "SpiderManStillAnimation.h"
#include <SDL_timer.h>

void SpiderManStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 10;

    vector<int> frame0 = {16, 14, 103, 94};
    vector<int> frame1 = {128, 13, 106, 95};
    vector<int> frame2 = {242, 12, 110, 96};
    vector<int> frame3 = {361, 10, 112, 98};
    vector<int> frame4 = {480, 11, 113, 97};
    vector<int> frame5 = {601, 12, 113, 96};
    vector<int> frame6 = {720, 12, 112, 96};
    vector<int> frame7 = {836, 12, 110, 96};
    vector<int> frame8 = {954, 12, 106, 95};
    vector<int> frame9 = {1066, 14, 104, 94};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame9);


}

SpiderManStillAnimation::SpiderManStillAnimation() : Animation() {

    this->init();

}