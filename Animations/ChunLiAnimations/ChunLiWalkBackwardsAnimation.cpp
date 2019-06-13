//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkBackwardsAnimation.h"
#include <SDL_timer.h>


void ChunLiWalkBackwardsAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 7;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 2 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiWalkBackwardsAnimation::ChunLiWalkBackwardsAnimation() : Animation() {
    this->init();
}

