//
// Created by arielpm on 30/05/19.
//

#include "VenomHitboxManager.h"

VenomHitboxManager::VenomHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 355, 257};

    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 315, 280};


    hitBoxes["still"] = {hitboxStill};
    hitBoxes["walk"] = {hitboxWalk};


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void VenomHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    currentState = state;
    iterHitboxes = hitBoxes.find(state);
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void VenomHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 10;
    currentHitbox.y = y;
}