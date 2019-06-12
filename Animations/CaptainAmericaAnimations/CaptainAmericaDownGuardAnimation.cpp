//
// Created by arielpm on 12/06/19.
//

#include "CaptainAmericaDownGuardAnimation.h"
#include <SDL_timer.h>



void CaptainAmericaDownGuardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 1;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = 2 * width;
    int initialY = 7 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }


}

CaptainAmericaDownGuardAnimation::CaptainAmericaDownGuardAnimation() : Animation() {

    this->init();

}