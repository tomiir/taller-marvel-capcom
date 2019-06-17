//
// Created by arielpm on 30/05/19.
//

#include "HitboxManager.h"

HitboxManager::HitboxManager() {

}

HitboxManager::~HitboxManager() = default;

void HitboxManager::move(DirectionVector *direction) {

    for(int i = 0; i < currentHitboxes.size(); i++) {
        currentHitboxes[i].x += (int) direction->x;
        currentHitboxes[i].y += (int) direction->y;
    }
}

void HitboxManager::setHitboxes(string newState, bool horizontalFlip, SDL_Rect spriteRect, SDL_Rect spriteRectFlip) {

    if(currentState == newState) return;
    currentState = newState;
    stateIterHitboxes = stateHitBoxes.find(newState);
    vector<SDL_Rect> newHitboxes = stateIterHitboxes->second;
    currentHitboxes = {};
    for (int i = 0; i < newHitboxes.size(); i++){
        SDL_Rect hitbox;
        if(!horizontalFlip) hitbox = SDL_Rect{spriteRect.x + newHitboxes[i].x , spriteRect.y + newHitboxes[i].y, newHitboxes[i].w, newHitboxes[i].h};
        else hitbox = SDL_Rect{spriteRectFlip.x + spriteRectFlip.w - newHitboxes[i].x - newHitboxes[i].w, spriteRectFlip.y + newHitboxes[i].y, newHitboxes[i].w, newHitboxes[i].h};
        currentHitboxes.push_back(hitbox);
    }
}


void HitboxManager::setInitialPosH(int x, int y, bool flip) {

}

vector<SDL_Rect> HitboxManager::getCurrentHitboxes() {
    return currentHitboxes;
}

void HitboxManager::stayInFloor(int yPos) {
    stateIterHitboxes = stateHitBoxes.find(currentState);
    vector<SDL_Rect> hitboxes = stateIterHitboxes->second;
    for (int i = 0; i < hitboxes.size(); i++) {
        currentHitboxes[i].y = yPos + hitboxes[i].y;
    }
}

