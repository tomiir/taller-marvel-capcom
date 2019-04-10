//
// Created by fer on 07/04/19.
//

#include <vector>
#include <algorithm>
#include "SpriteManager.h"

SpriteManager::SpriteManager() {}

void SpriteManager::setState(string state_) {

    if(stateChanges(state_)) {
        actualAnimation->resetIndex();
        state = state_;
        itr = animationMap.find(state);
        actualAnimation = itr->second;
    }

}

SDL_Rect SpriteManager::getSprite() {

    vector<int> infoSprite = actualAnimation->play();
    SDL_Rect currentSprite {infoSprite[0], infoSprite[1], infoSprite[2], infoSprite[3]};
    return currentSprite;
}

bool SpriteManager::stateChanges(string newState) {

    return state != newState;
}

void SpriteManager::init() {}



