//
// Created by arielpm on 09/04/19.
//

#include "CaptainAmericaWalkFowardAnimation.h"
#include <SDL_timer.h>

void CaptainAmericaWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 6;
    animationLength = 5;
    int width = 322;
    int height = 245;
    int initialX = 0;
    int initialY = height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

CaptainAmericaWalkFowardAnimation::CaptainAmericaWalkFowardAnimation() : Animation() {

    this->init();

}