//
// Created by arielpm on 13/04/19.
//

#include <SDL_timer.h>
#include "ChunLiStillAnimation.h"



void ChunLiStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 9;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 0;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStillAnimation::ChunLiStillAnimation() : Animation() {
    this->init();
}
