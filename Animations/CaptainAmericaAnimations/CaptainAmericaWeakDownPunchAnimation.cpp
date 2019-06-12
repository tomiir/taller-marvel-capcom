//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakDownPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaWeakDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 13 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaWeakDownPunchAnimation::CaptainAmericaWeakDownPunchAnimation() : Animation() {

    this->init();

}