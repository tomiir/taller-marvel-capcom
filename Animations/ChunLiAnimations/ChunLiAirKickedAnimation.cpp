//
// Created by fer on 12/06/19.
//

#include "ChunLiAirKickedAnimation.h"
#include <SDL_timer.h>



void ChunLiAirKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 407;
    int height = 210;
    int initialX = width;
    int initialY = 5 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiAirKickedAnimation::ChunLiAirKickedAnimation() : Animation() {
    this->init();
}