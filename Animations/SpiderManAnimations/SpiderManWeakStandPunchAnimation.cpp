//
// Created by fer on 12/06/19.
//

#include "SpiderManWeakStandPunchAnimation.h"
#include <SDL_timer.h>


void SpiderManWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 4;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 14 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManWeakStandPunchAnimation::SpiderManWeakStandPunchAnimation() : Animation() {
    this->init();
}
