//
// Created by arielpm on 13/04/19.
//

#include "ChunLiJumpAnimation.h"
#include <SDL_timer.h>

void ChunLiJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 9;

    vector<int> frame0 = {0, 840, 407, 210};
    vector<int> frame1 = {407, 840, 407, 210};
    vector<int> frame2 = {814, 840, 407, 210};
    vector<int> frame3 = {1221, 840, 407, 210};
    vector<int> frame4 = {1628, 840, 407, 210};
    vector<int> frame5 = {2035, 840, 407, 210};
    vector<int> frame6 = {2442, 840, 407, 210};
    vector<int> frame7 = {2849, 840, 407, 210};
    vector<int> frame8 = {3256, 840, 407, 210};


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

ChunLiJumpAnimation::ChunLiJumpAnimation() : Animation() {

    this->init();
}