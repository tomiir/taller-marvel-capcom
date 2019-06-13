//
// Created by fer on 12/06/19.
//

#include "VenomStandKickedAnimation.h"
#include <SDL_timer.h>


void VenomStandKickedAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 560;
    int height = 238;
    int initialX = 2 * width;
    int initialY = 5 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }

}

VenomStandKickedAnimation::VenomStandKickedAnimation() : Animation() {
    this->init();
}