//
// Created by fer on 12/06/19.
//

#include "SpiderManWeakStandKickAnimation.h"
#include <SDL_timer.h>


void SpiderManWeakStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 3;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 15 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManWeakStandKickAnimation::SpiderManWeakStandKickAnimation() : Animation() {
    this->init();
}
