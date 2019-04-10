//
// Created by fer on 06/04/19.
//

#include "Animation.h"
#include "../utils/TextureManager/TextureManager.h"

Animation::Animation() {}

Animation::~Animation() = default;

vector<int> Animation::play() {

    if(index == animation.size()){
        resetIndex();
    }

    int frameToDraw = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;

    vector<int> sprite = animation[frameToDraw];

    return sprite;

}

void Animation::resetIndex() {

    index = 0;

}

void Animation::init() {


}
