//
// Created by fer on 12/06/19.
//

#include "SpiderManStrongAirPunchAnimation.h"
#include <SDL_timer.h>


void SpiderManStrongAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 6;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 9 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStrongAirPunchAnimation::SpiderManStrongAirPunchAnimation() : Animation() {
    this->init();
}
