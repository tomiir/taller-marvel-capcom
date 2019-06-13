//
// Created by fer on 12/06/19.
//

#include "ChunLiWeakAirPunchAnimation.h"
#include <SDL_timer.h>



void ChunLiWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 3;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 12 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiWeakAirPunchAnimation::ChunLiWeakAirPunchAnimation() : Animation() {
    this->init();
}