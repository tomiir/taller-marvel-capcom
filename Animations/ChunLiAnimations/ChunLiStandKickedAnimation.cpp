//
// Created by fer on 12/06/19.
//

#include "ChunLiStandKickedAnimation.h"
#include <SDL_timer.h>



void ChunLiStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 407;
    int height = 210;
    int initialX = 2*width;
    int initialY = 5 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStandKickedAnimation::ChunLiStandKickedAnimation() : Animation() {
    this->init();
}