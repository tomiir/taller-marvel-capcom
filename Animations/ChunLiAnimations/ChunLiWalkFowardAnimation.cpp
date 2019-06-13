//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkFowardAnimation.h"
#include <SDL_timer.h>
#include <SDL_timer.h>



void ChunLiWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 8;
    animationLength = 12;
    int width = 407;
    int height = 210;
    int initialX = 0;
    int initialY = height;

    for(int i = 0; i < animationLength; i++){
        vector<int> frame = {initialX, initialY, height, width};
        initialX += width;
        animation.push_back(frame);
    }
}

ChunLiWalkFowardAnimation::ChunLiWalkFowardAnimation() : Animation() {
    this->init();
}