//
// Created by arielpm on 22/06/19.
//

#include "ChunLiProjectileHitboxManager.h"

ChunLiProjectileHitboxManager::ChunLiProjectileHitboxManager() : HitboxManager(){

    currentState = "flying";

    SDL_Rect hitboxFlying = SDL_Rect{510, 255, 55, 63};

    stateHitBoxes["flying"] = { hitboxFlying };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void ChunLiProjectileHitboxManager::setInitialPosH(int x, int y, bool flip) {
    return;
}