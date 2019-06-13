//
// Created by fer on 12/06/19.
//

#include "SpiderManStandKickedAnimation.h"
#include <SDL_timer.h>


void SpiderManStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;

    int width = 491;
    int height = 268;
    int initialX = 2 * width;
    int initialY = 5 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStandKickedAnimation::SpiderManStandKickedAnimation() : Animation() {
    this->init();
}
