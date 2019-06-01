//
// Created by arielpm on 30/05/19.
//

#include "SpiderManHitboxManager.h"

SpiderManHitboxManager::SpiderManHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 223, 200};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 160, 185};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 207, 167};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 238, 130};

    hitBoxes["still"] = hitboxStill;
    hitBoxes["walk"] = hitboxWalk;
    hitBoxes["jump"] = hitboxJump;
    hitBoxes["entering"] = hitboxJump;
    hitBoxes["leaving"] = hitboxJump;
    hitBoxes["crowchedDown"] = hitboxCrowchedDown;


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void SpiderManHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    iterHitboxes = hitBoxes.find(state);

    if(state == "crowchedDown"){
        int aux = currentHitbox.h - iterHitboxes->second.h - 40;
        y = y + aux;
    }

    if(currentState == "crowchedDown"){
        int aux = iterHitboxes->second.h - currentHitbox.h + 40;
        y = y - aux;
    }

    currentState = state;
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void SpiderManHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 26;
    currentHitbox.y = y + 40;
}