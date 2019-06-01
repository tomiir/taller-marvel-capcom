//
// Created by arielpm on 30/05/19.
//

#include "VenomHitboxManager.h"

VenomHitboxManager::VenomHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 245, 230};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 182, 295};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 230, 170};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 280, 200};


    hitBoxes["still"] = hitboxStill;
    hitBoxes["walk"] = hitboxWalk;
    hitBoxes["jump"] = hitboxJump;
    hitBoxes["crowchedDown"] = hitboxCrowchedDown;


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void VenomHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    iterHitboxes = hitBoxes.find(state);

    if(state == "crowchedDown"){
        int aux = abs(currentHitbox.h - iterHitboxes->second.h);
        y = y + aux;
        x = x - 65;
    }

    if(currentState == "crowchedDown"){
        int aux = abs(iterHitboxes->second.h - currentHitbox.h);
        y = y - aux;
        x = x + 65;

    }

    if (currentState == "walk"){
        int aux = abs(currentHitbox.h - iterHitboxes->second.h);
        y = y + aux;
    }

    if(state == "walk"){
        int aux = abs(iterHitboxes->second.h - currentHitbox.h);
        y = y - aux;
    }


    currentState = state;
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void VenomHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 65;
    currentHitbox.y = y + 65;
}