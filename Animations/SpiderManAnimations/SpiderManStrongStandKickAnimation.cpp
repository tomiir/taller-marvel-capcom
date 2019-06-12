//
// Created by fer on 12/06/19.
//

#include "SpiderManStrongStandKickAnimation.h"
#include <SDL_timer.h>


void SpiderManStrongStandKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 9;
    animationLength = 7;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 18 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStrongStandKickAnimation::SpiderManStrongStandKickAnimation() : Animation() {
    this->init();
}
