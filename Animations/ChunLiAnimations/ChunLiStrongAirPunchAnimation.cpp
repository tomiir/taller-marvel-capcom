//
// Created by fer on 12/06/19.
//

#include "ChunLiStrongAirPunchAnimation.h"
#include <SDL_timer.h>



void ChunLiStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 9 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiStrongAirPunchAnimation::ChunLiStrongAirPunchAnimation() : Animation() {
    this->init();
}