//
// Created by fer on 06/04/19.
//

#include "Animation.h"
#include "../utils/TextureManager/TextureManager.h"

Animation::Animation() {}

Animation::~Animation() = default;

vector<int> Animation::play() {


//    frameToDraw = ((SDL_GetTicks() - startTime) * animationRate / 1000) % animationLength;

    if (counter == animationRate){
        frameToDraw++;
        counter = 0;
    }
    counter++;

    if(frameToDraw == animation.size()){
        resetIndex();
    }

    vector<int> sprite = animation[frameToDraw];

    return sprite;

}

void Animation::resetIndex() {

    frameToDraw = 0;
    counter = 0;

}

void Animation::init() {


}
