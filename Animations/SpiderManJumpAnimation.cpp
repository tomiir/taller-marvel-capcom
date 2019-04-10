//
// Created by arielpm on 09/04/19.
//

#include "SpiderManJumpAnimation.h"
#include <SDL_timer.h>

void SpiderManJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 15;

    vector<int> frame0 = {12, 429, 83, 56};
    vector<int> frame1 = {119, 229, 64, 139};
    vector<int> frame2 = {197, 229, 83, 103};
    vector<int> frame3 = {291, 235, 99, 67};
    vector<int> frame4 = {399, 235, 98, 52};
    vector<int> frame5 = {502, 234, 99, 50};
    vector<int> frame6 = {606, 234, 98, 52};
    vector<int> frame7 = {709, 233, 99, 67};
    vector<int> frame8 = {815, 234, 108, 98};
    vector<int> frame9 = {929, 228, 102, 133};
    vector<int> frame10 = {1038, 223, 100, 133};
    vector<int> frame11 = {1285, 434, 95, 82};
    vector<int> frame12 = {1395, 459, 83, 55};
    vector<int> frame13 = {1490, 446, 99, 63};
    vector<int> frame14 = {1602, 418, 119, 94};



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
    animation.push_back(frame10);
    animation.push_back(frame11);
    animation.push_back(frame12);
    animation.push_back(frame13);
    animation.push_back(frame14);


}

SpiderManJumpAnimation::SpiderManJumpAnimation() : Animation() {

    this->init();

}