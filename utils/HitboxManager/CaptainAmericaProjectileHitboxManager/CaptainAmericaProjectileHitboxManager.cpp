//
// Created by arielpm on 22/06/19.
//

#include "CaptainAmericaProjectileHitboxManager.h"


CaptainAmericaProjectileHitboxManager::CaptainAmericaProjectileHitboxManager() : HitboxManager(){

    currentState = "flying";

    SDL_Rect hitboxFlying = SDL_Rect{520, 290, 148, 48};

    stateHitBoxes["flying"] = { hitboxFlying };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void CaptainAmericaProjectileHitboxManager::setInitialPosH(int x, int y, bool flip) {
    return;
}