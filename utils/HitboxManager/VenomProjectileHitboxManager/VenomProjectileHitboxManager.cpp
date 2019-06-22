//
// Created by arielpm on 22/06/19.
//

#include "VenomProjectileHitboxManager.h"

VenomProjectileHitboxManager::VenomProjectileHitboxManager() : HitboxManager(){

    currentState = "flying";

    SDL_Rect hitboxFlying = SDL_Rect{718, 295, 80, 25};

    stateHitBoxes["flying"] = { hitboxFlying };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void VenomProjectileHitboxManager::setInitialPosH(int x, int y, bool flip) {
    return;
}