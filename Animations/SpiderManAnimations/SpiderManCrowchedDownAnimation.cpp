//
// Created by arielpm on 09/04/19.
//

#include "SpiderManCrowchedDownAnimation.h"
#include <SDL_timer.h>


void SpiderManCrowchedDownAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 3 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManCrowchedDownAnimation::SpiderManCrowchedDownAnimation() : Animation() {
    this->init();
}

