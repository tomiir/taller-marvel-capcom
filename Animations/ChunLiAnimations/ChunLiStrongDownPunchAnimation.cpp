//
// Created by fer on 12/06/19.
//

#include "ChunLiStrongDownPunchAnimation.h"
#include <SDL_timer.h>



void ChunLiStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 10 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStrongDownPunchAnimation::ChunLiStrongDownPunchAnimation() : Animation() {
    this->init();
}