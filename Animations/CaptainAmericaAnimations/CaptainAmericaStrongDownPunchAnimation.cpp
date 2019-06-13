//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaStrongDownPunchAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaStrongDownPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 3;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 10 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, width, height};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaStrongDownPunchAnimation::CaptainAmericaStrongDownPunchAnimation() : Animation() {

    this->init();

}