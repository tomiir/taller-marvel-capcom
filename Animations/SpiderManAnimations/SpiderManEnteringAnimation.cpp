//
// Created by arielpm on 13/04/19.
//

#include "SpiderManEnteringAnimation.h"
#include <SDL_timer.h>

void SpiderManEnteringAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 10;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 22 * height;

    for(int i = 0; i < animationLength; i++){
        initialX += width;
        if(i == 2 or i == 4) continue;
        vector<int> frame = {initialX, initialY, height, width};
        animation.push_back(frame);
    }
}

SpiderManEnteringAnimation::SpiderManEnteringAnimation() : Animation() {

    this->init();

}