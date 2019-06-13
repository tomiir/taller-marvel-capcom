//
// Created by fer on 12/06/19.
//

#include "ChunLiGrabAnimation.h"
#include <SDL_timer.h>



void ChunLiGrabAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 4;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 21 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiGrabAnimation::ChunLiGrabAnimation() : Animation() {
    this->init();
}