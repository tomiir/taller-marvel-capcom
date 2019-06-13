//
// Created by arielpm on 13/04/19.
//

#include "ChunLiEnteringAnimation.h"
#include <SDL_timer.h>


void ChunLiEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 4;
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

ChunLiEnteringAnimation::ChunLiEnteringAnimation() : Animation() {
    this->init();
}