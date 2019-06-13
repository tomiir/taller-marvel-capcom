//
// Created by fer on 12/06/19.
//

#include "SpiderManDownGuardAnimation.h"
#include <SDL_timer.h>


void SpiderManDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 7;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 7 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManDownGuardAnimation::SpiderManDownGuardAnimation() : Animation() {
    this->init();
}

