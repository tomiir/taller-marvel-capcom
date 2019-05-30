//
// Created by arielpm on 30/05/19.
//

#include "SpiderManHitboxManager.h"

SpiderManHitboxManager::SpiderManHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 263, 240};

    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 200, 225};


    hitBoxes["still"] = {hitboxStill};
    hitBoxes["walk"] = {hitboxWalk};


    iterHitboxes = hitBoxes.find(currentState);
    currentHitbox = iterHitboxes->second;
}

void SpiderManHitboxManager::setHitbox(string state) {

    int x = currentHitbox.x;
    int y = currentHitbox.y;

    currentState = state;
    iterHitboxes = hitBoxes.find(state);
    currentHitbox = iterHitboxes->second;

    currentHitbox.x = x;
    currentHitbox.y = y;
}

void SpiderManHitboxManager::setInitialPos(int x, int y) {

    currentHitbox.x = x + 6;
    currentHitbox.y = y;
}