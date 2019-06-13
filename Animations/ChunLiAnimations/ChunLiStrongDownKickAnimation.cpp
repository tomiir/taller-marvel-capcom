//
// Created by fer on 12/06/19.
//

#include "ChunLiStrongDownKickAnimation.h"
#include <SDL_timer.h>



void ChunLiStrongDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 6;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 20 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStrongDownKickAnimation::ChunLiStrongDownKickAnimation() : Animation() {
    this->init();
}