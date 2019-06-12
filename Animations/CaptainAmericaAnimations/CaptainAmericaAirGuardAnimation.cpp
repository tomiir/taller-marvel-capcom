//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaAirGuardAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaAirGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = 2 * width;
    int initialY = 8 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaAirGuardAnimation::CaptainAmericaAirGuardAnimation() : Animation() {

    this->init();

}