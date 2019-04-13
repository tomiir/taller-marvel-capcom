//
// Created by arielpm on 13/04/19.
//

#include "ChunLiWalkFowardAnimation.h"
#include <SDL_timer.h>

void ChunLiWalkFowardAnimation::init() {

    startTime = SDL_GetTicks();
    animationRate = 12;
    animationLength = 11;
    vector<vector<int>> frames = {
            {32, 328, 80, 82},
            {131, 330, 65, 84},
            {209, 330, 64, 85},
            {287, 333, 65, 84},
            {369, 332, 74, 83},
            {447, 336, 79, 82},
            {533, 335, 74, 83},
            {613, 336, 65, 84},
            {685, 336, 64, 85},
            {756, 337, 65, 84},
            {823, 337, 73, 83}
    };

    for (int i = 0; i< animationLength; i++) {
        animation.push_back(frames[i]);
    }
}

ChunLiWalkFowardAnimation::ChunLiWalkFowardAnimation() : Animation() {

    this->init();

}