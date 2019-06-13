//
// Created by fer on 12/06/19.
//

#include "SpiderManDownKickedAnimation.h"
#include <SDL_timer.h>


void SpiderManDownKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 2;
    animationLength = 1;

    int width = 491;
    int height = 268;
    int initialX = 0;
    int initialY = 5 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }

}

SpiderManDownKickedAnimation::SpiderManDownKickedAnimation() : Animation() {
    this->init();
}
