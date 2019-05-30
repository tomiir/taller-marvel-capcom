//
// Created by arielpm on 30/05/19.
//

#include "ChunLiHitboxManager.h"

ChunLiHitboxManager::ChunLiHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 201, 217};

    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 162, 210};


    hitBoxes["still"] = {hitboxStill};
    hitBoxes["walk"] = {hitboxWalk};


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void ChunLiHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    currentState = state;
    iterHitboxes = hitBoxes.find(state);
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void ChunLiHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 7;
    currentHitbox.y = y;
}