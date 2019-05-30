//
// Created by arielpm on 30/05/19.
//

#include "CaptainAmericaHitboxManager.h"

CaptainAmericaHitboxManager::CaptainAmericaHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 200, 277};

    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 145, 282};


    hitBoxes["still"] = {hitboxStill};
    hitBoxes["walk"] = {hitboxWalk};


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void CaptainAmericaHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    currentState = state;
    iterHitboxes = hitBoxes.find(state);
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void CaptainAmericaHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 6;
    currentHitbox.y = y;
}


