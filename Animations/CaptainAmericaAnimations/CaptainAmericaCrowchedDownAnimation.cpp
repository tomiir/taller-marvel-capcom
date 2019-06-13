//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaCrowchedDownAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 3 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

CaptainAmericaCrowchedDownAnimation::CaptainAmericaCrowchedDownAnimation() : Animation() {

    this->init();

}

