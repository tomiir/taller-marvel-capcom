//
// Created by arielpm on 09/04/19.
//

#include "SpiderManCrowchedDownAnimation.h"
#include <SDL_timer.h>

void SpiderManCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 10;

    vector<int> frame0 = {2, 1178, 102, 94};
    vector<int> frame1 = {108, 1176, 99, 94};
    vector<int> frame2 = {227, 1176, 100, 94};
    vector<int> frame3 = {331, 1176, 100, 94};
    vector<int> frame4 = {434, 1176, 100, 94};
    vector<int> frame5 = {537, 1176, 100, 94};
    vector<int> frame6 = {640, 1176, 100, 94};
    vector<int> frame7 = {743, 1176, 100, 94};
    vector<int> frame8 = {1177, 1176, 100, 94};
    vector<int> frame9 = {1282, 1176, 102, 94};


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

SpiderManCrowchedDownAnimation::SpiderManCrowchedDownAnimation() : Animation() {

    this->init();

}