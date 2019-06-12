//
// Created by fer on 12/06/19.
//

#include "SpiderManStrongDownPunchAnimation.h"
#include <SDL_timer.h>


void SpiderManStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 7;
    animationLength = 5;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 10 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStrongDownPunchAnimation::SpiderManStrongDownPunchAnimation() : Animation() {
    this->init();
}
