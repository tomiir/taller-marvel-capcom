//
// Created by fer on 12/06/19.
//

#include "SpiderManWeakDownKickAnimation.h"
#include <SDL_timer.h>


void SpiderManWeakDownKickAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 3;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 17* height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManWeakDownKickAnimation::SpiderManWeakDownKickAnimation() : Animation() {
    this->init();
}
