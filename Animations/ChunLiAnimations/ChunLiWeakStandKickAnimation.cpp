//
// Created by fer on 12/06/19.
//

#include "ChunLiWeakStandKickAnimation.h"
#include <SDL_timer.h>



void ChunLiWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 4;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = 15 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiWeakStandKickAnimation::ChunLiWeakStandKickAnimation() : Animation() {
    this->init();
}