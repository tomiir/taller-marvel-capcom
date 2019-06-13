//
// Created by fer on 12/06/19.
//

#include "ChunLiStrongStandPunchAnimation.h"
#include <SDL_timer.h>



void ChunLiStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 11 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStrongStandPunchAnimation::ChunLiStrongStandPunchAnimation() : Animation() {
    this->init();
}