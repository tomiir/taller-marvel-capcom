//
// Created by arielpm on 13/04/19.
//

#include "ChunLiCrowchedDownAnimation.h"
#include <SDL_timer.h>


void ChunLiCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 2;
    int width = 407;
    int height = 210;
    int initialX = width;
    int initialY = 3 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiCrowchedDownAnimation::ChunLiCrowchedDownAnimation() : Animation() {
    this->init();
}