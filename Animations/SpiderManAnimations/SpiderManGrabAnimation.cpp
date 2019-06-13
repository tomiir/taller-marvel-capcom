//
// Created by fer on 12/06/19.
//

#include "SpiderManGrabAnimation.h"
#include <SDL_timer.h>


void SpiderManGrabAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 11;
    animationLength = 9;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 21 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManGrabAnimation::SpiderManGrabAnimation() : Animation() {
    this->init();
}
