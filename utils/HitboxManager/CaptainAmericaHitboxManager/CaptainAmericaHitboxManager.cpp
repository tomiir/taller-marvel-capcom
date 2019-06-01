//
// Created by arielpm on 30/05/19.
//

#include "CaptainAmericaHitboxManager.h"

CaptainAmericaHitboxManager::CaptainAmericaHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 160, 277};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 145, 282};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 157, 215};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 162, 195};


    hitBoxes["still"] = hitboxStill;
    hitBoxes["walk"] = hitboxWalk;
    hitBoxes["jump"] = hitboxJump;
    hitBoxes["entering"] = hitboxJump;
    hitBoxes["leaving"] = hitboxJump;
    hitBoxes["crowchedDown"] = hitboxCrowchedDown;


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void CaptainAmericaHitboxManager::setHitbox(string state) {

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

    if (state == "walk"){
        x = x + 30;
    }

    if(currentState == "walk"){
        x = x - 30;
    }

    currentState = state;
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void CaptainAmericaHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 26;
    currentHitbox.y = y;
}


