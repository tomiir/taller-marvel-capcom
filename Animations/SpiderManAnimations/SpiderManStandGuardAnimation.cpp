//
// Created by fer on 12/06/19.
//

#include "SpiderManStandGuardAnimation.h"
#include <SDL_timer.h>


void SpiderManStandGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 8;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 6 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStandGuardAnimation::SpiderManStandGuardAnimation() : Animation() {
    this->init();
}
