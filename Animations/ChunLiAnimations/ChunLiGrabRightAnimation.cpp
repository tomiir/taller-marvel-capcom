//
// Created by arielpm on 25/06/19.
//

#include "ChunLiGrabRightAnimation.h"
#include <SDL_timer.h>

void ChunLiGrabRightAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 14;

    vector<int> frame0 = {0, 4410, 407, 210};
    vector<int> frame1 = {407, 4410, 407, 210};
    vector<int> frame2 = {814, 4410, 407, 210};
    vector<int> frame3 = {1221, 4410, 407, 210};

    vector<int> frame4 = {0, 0, 407, 210};
    vector<int> frame5 = {407, 0, 407, 210};
    vector<int> frame6 = {814, 0, 407, 210};
    vector<int> frame7 = {1221, 0, 407, 210};
    vector<int> frame8 = {1628, 0, 407, 210};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame5);
    animation.push_back(frame6);
    animation.push_back(frame6);
    animation.push_back(frame7);
    animation.push_back(frame7);
    animation.push_back(frame8);
    animation.push_back(frame8);
}

ChunLiGrabRightAnimation::ChunLiGrabRightAnimation() : Animation() {

    this->init();

}