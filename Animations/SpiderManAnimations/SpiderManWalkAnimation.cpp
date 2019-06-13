//
// Created by arielpm on 09/04/19.
//

#include "SpiderManWalkAnimation.h"
#include <SDL_timer.h>


void SpiderManWalkAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 13;
    animationLength = 12;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 1 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManWalkAnimation::SpiderManWalkAnimation() : Animation() {
    this->init();
}
