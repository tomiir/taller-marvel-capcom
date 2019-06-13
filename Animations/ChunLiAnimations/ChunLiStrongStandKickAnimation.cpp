//
// Created by fer on 12/06/19.
//

#include "ChunLiStrongStandKickAnimation.h"
#include <SDL_timer.h>



void ChunLiStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 8;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 18 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStrongStandKickAnimation::ChunLiStrongStandKickAnimation() : Animation() {
    this->init();
}