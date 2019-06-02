//
// Created by arielpm on 30/05/19.
//

#include "HitboxManager.h"

HitboxManager::HitboxManager() {

}

HitboxManager::~HitboxManager() = default;

void HitboxManager::move(DirectionVector *direction) {

    for(int i = 0; i< currentHitboxes.size(); i++) {
        SDL_Rect currentHitbox = currentHitboxes[i];
        currentHitbox.x += (int) direction->x;
        currentHitbox.y += (int) direction->y;
    }
}

void HitboxManager::setHitboxes(string state, bool horizontalFlip) {

    //Aca habría que ver como setear bien la x y la y de las nuevos estados
    //Por ejemplo si pasa a estar agachado vamos a tener que cambia la y

    currentState = state;
    stateIterHitboxes = stateHitBoxes.find(state);
    currentHitboxes = stateIterHitboxes->second;
}

void HitboxManager::setInitialPos(int x, int y) {

}

vector<SDL_Rect> HitboxManager::getCurrentHitboxes() {
    return currentHitboxes;
}

void HitboxManager::stayInFloor(int initialY) {
    for (int i = 0; i < currentHitboxes.size(); i++) {
        SDL_Rect currentHitbox = currentHitboxes[i];
        currentHitbox.y = initialY;
    }
}

