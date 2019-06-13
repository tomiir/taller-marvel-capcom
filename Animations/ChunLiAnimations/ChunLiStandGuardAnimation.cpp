//
// Created by fer on 12/06/19.
//

#include "ChunLiStandGuardAnimation.h"
#include <SDL_timer.h>



void ChunLiStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 6 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStandGuardAnimation::ChunLiStandGuardAnimation() : Animation() {
    this->init();
}