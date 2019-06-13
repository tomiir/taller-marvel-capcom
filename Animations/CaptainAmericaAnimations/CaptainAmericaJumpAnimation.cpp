//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaJumpAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 3;
    animationLength = 4;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 4 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaJumpAnimation::CaptainAmericaJumpAnimation() : Animation() {

    this->init();

}