//
// Created by arielpm on 22/06/19.
//

#include "SpiderManProjectileHitboxManager.h"

SpiderManProjectileHitboxManager::SpiderManProjectileHitboxManager() : HitboxManager(){

    currentState = "flying";

    SDL_Rect hitboxFlying = SDL_Rect{538, 353, 193, 53};

    stateHitBoxes["flying"] = { hitboxFlying };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void SpiderManProjectileHitboxManager::setInitialPosH(int x, int y, bool flip) {
    return;
}