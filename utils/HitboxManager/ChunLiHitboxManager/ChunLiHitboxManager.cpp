//
// Created by arielpm on 30/05/19.
//

#include "ChunLiHitboxManager.h"

ChunLiHitboxManager::ChunLiHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 141, 217};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 122, 210};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 130, 185};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 165, 175};

    hitBoxes["still"] = hitboxStill;
    hitBoxes["walk"] = hitboxWalk;
    hitBoxes["jump"] = hitboxJump;
    hitBoxes["entering"] = hitboxJump;
    hitBoxes["leaving"] = hitboxJump;
    hitBoxes["crowchedDown"] = hitboxCrowchedDown;


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void ChunLiHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    iterHitboxes = hitBoxes.find(state);

    if(state == "crowchedDown"){
        int aux = currentHitbox.h - iterHitboxes->second.h;
        y = y + aux;
    }

    if(currentState == "crowchedDown"){
        int aux = iterHitboxes->second.h - currentHitbox.h;
        y = y - aux;
    }

    currentState = state;
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void ChunLiHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 32;
    currentHitbox.y = y;
}