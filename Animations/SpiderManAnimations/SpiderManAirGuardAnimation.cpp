//
// Created by fer on 12/06/19.
//

#include "SpiderManAirGuardAnimation.h"
#include <SDL_timer.h>


void SpiderManAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 6;
    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 8 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManAirGuardAnimation::SpiderManAirGuardAnimation() : Animation() {
    this->init();
}