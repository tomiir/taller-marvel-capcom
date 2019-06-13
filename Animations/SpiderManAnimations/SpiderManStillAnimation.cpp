//
// Created by arielpm on 09/04/19.
//

#include "SpiderManStillAnimation.h"
#include <SDL_timer.h>


void SpiderManStillAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 9;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 0;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStillAnimation::SpiderManStillAnimation() : Animation() {
    this->init();
}