//
// Created by arielpm on 09/04/19.
//

#include "SpiderManCrowchedDownAnimation.h"
#include <SDL_timer.h>

void SpiderManCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 10;

    vector<int> frame0 = {2, 1216, 102, 56};
    vector<int> frame1 = {108, 1218, 99, 52};
    vector<int> frame2 = {227, 1220, 100, 50};
    vector<int> frame3 = {331, 1220, 100, 50};
    vector<int> frame4 = {434, 1220, 100, 50};
    vector<int> frame5 = {537, 1219, 100, 51};
    vector<int> frame6 = {640, 1219, 100, 51};
    vector<int> frame7 = {743, 1219, 100, 51};
    vector<int> frame8 = {1177, 1223, 100, 47};
    vector<int> frame9 = {1282, 1214, 102, 56};


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