//
// Created by arielpm on 22/06/19.
//

#include "ChunLiProjectileAnimation.h"
#include <SDL_timer.h>

void ChunLiProjectileAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 4;

    vector<int> frame0 = {0, 0, 407, 210};
    vector<int> frame1 = {407, 0, 407, 210};
    vector<int> frame2 = {814, 0, 407, 210};
    vector<int> frame3 = {1221, 0, 407, 210};


    animation.push_back(frame0);
    animation.push_back(frame1);
    animation.push_back(frame2);
    animation.push_back(frame3);

}

ChunLiProjectileAnimation::ChunLiProjectileAnimation() : Animation() {

    this->init();
}