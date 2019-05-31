//
// Created by arielpm on 30/05/19.
//

#include "HitboxManager.h"

HitboxManager::HitboxManager() {

}

HitboxManager::~HitboxManager() = default;

void HitboxManager::move(DirectionVector *direction) {

    currentHitbox.x += (int) direction->x;
    currentHitbox.y += (int) direction->y;

}

void HitboxManager::setHitbox(string state) {

    //Aca habría que ver como setear bien la x y la y de las nuevos estados
    //Por ejemplo si pasa a estar agachado vamos a tener que cambia la y

    currentState = state;
    iterHitboxes = hitBoxes.find(state);
    currentHitbox = iterHitboxes->second;
}

void HitboxManager::setInitialPos(int x, int y) {

}

SDL_Rect HitboxManager::getCurrentHitbox() {
    return currentHitbox;
}

void HitboxManager::stayInFloor(int initialY) {

    currentHitbox.y = initialY;
}
