//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongStandPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 10;
    animationLength = 6;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 11 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaStrongStandPunchAnimation::CaptainAmericaStrongStandPunchAnimation() : Animation() {

    this->init();

}