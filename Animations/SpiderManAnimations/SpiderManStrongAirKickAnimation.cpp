//
// Created by fer on 12/06/19.
//

#include "SpiderManStrongAirKickAnimation.h"
#include <SDL_timer.h>


void SpiderManStrongAirKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 6;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 19 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManStrongAirKickAnimation::SpiderManStrongAirKickAnimation() : Animation() {
    this->init();
}
