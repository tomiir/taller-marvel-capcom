//
// Created by arielpm on 13/04/19.
//

#include "ChunLiJumpAnimation.h"
#include <SDL_timer.h>



void ChunLiJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 9;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 4 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiJumpAnimation::ChunLiJumpAnimation() : Animation() {
    this->init();
}