//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkBackwadsAnimation.h"
#include <SDL_timer.h>

void ChunLiWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;

    vector<int> frame0 = {0, 420, 407, 210};
    vector<int> frame1 = {407, 420, 407, 210};
    vector<int> frame2 = {814, 420, 407, 210};
    vector<int> frame3 = {1221, 420, 407, 210};
    vector<int> frame4 = {1628, 420, 407, 210};
    vector<int> frame5 = {2035, 420, 407, 210};
    vector<int> frame6 = {2442, 420, 407, 210};



    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);
    animation.push_back(frame4);
    animation.push_back(frame5);
    animation.push_back(frame6);


}

ChunLiWalkBackwardsAnimation::ChunLiWalkBackwardsAnimation() : Animation() {

    this->init();

}