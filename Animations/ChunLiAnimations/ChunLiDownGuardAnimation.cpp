//
// Created by fer on 12/06/19.
//

#include "ChunLiDownGuardAnimation.h"
#include <SDL_timer.h>



void ChunLiDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 7 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiDownGuardAnimation::ChunLiDownGuardAnimation() : Animation() {
    this->init();
}