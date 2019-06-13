//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaGrabAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaGrabAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 5;
    animationLength = 7;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = 21 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaGrabAnimation::CaptainAmericaGrabAnimation() : Animation() {

    this->init();

}