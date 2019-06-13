//
// Created by arielpm on 09/04/19.
//

#include "SpiderManJumpAnimation.h"
#include <SDL_timer.h>


void SpiderManJumpAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 5;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 4 * height;

    for(int i = 0; i < animationLength; i++){
        initialX += width;
        if(i == 0) continue;
        vector<int> frame = {initialX, initialY, height, width};
        animation.push_back(frame);
    }

}

SpiderManJumpAnimation::SpiderManJumpAnimation() : Animation() {
    this->init();
}