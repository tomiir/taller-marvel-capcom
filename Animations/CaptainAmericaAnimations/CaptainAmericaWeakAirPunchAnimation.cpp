//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaWeakAirPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaWeakAirPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = width;
    int initialY = 12 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaWeakAirPunchAnimation::CaptainAmericaWeakAirPunchAnimation() : Animation() {

    this->init();

}