//
// Created by fer on 12/06/19.
//

#include "ChunLiAirGuardAnimation.h"
#include <SDL_timer.h>



void ChunLiAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 2;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 8 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiAirGuardAnimation::ChunLiAirGuardAnimation() : Animation() {
    this->init();
}