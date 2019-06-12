//
// Created by trocchi on 6/1/19.
//

#include "CaptainAmericaWeakStandPunchAnimation.h"
#include <SDL_timer.h>


void CaptainAmericaWeakStandPunchAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 4;
    animationLength = 1;
    int width = 322;
    int height = 245;
    int initialX = 2 * width;
    int initialY = 14 * height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaWeakStandPunchAnimation::CaptainAmericaWeakStandPunchAnimation() : Animation() {

    this->init();

}
