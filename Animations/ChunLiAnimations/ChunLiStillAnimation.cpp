//
// Created by arielpm on 13/04/19.
//

#include <SDL_timer.h>
#include "ChunLiStillAnimation.h"

void ChunLiStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;

    vector<int> frame0 = {0, 0, 407, 210};
    vector<int> frame1 = {407, 0, 407, 210};
    vector<int> frame2 = {814, 0, 407, 210};
    vector<int> frame3 = {1221, 0, 407, 210};
    vector<int> frame4 = {1628, 0, 407, 210};
    vector<int> frame5 = {2035, 0, 407, 210};
    vector<int> frame6 = {2442, 0, 407, 210};
    vector<int> frame7 = {2849, 0, 407, 210};
    vector<int> frame8 = {3256, 0, 407, 210};



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

ChunLiStillAnimation::ChunLiStillAnimation() : Animation() {

    this->init();

}