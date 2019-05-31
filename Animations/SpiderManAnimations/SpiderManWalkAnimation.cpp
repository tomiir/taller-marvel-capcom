//
// Created by arielpm on 09/04/19.
//

#include "SpiderManWalkAnimation.h"
#include <SDL_timer.h>

void SpiderManWalkAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 13;
    animationLength = 12;

    vector<int> frame0 = {7, 122, 81, 90};
    vector<int> frame1 = {97, 121, 87, 91};
    vector<int> frame2 = {191, 119, 82, 92};
    vector<int> frame3 = {277, 119, 84, 90};
    vector<int> frame4 = {371, 120, 79, 90};
    vector<int> frame5 = {453, 120, 84, 90};
    vector<int> frame6 = {540, 121, 81, 90};
    vector<int> frame7 = {624, 122, 78, 90};
    vector<int> frame8 = {710, 121, 76, 90};
    vector<int> frame9 = {796, 122, 74, 92};
    vector<int> frame10 = {881, 123, 72, 92};
    vector<int> frame11 = {956, 121, 83, 89};



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


}

SpiderManWalkAnimation::SpiderManWalkAnimation() : Animation() {

    this->init();

}