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
    SDL_Rect hitboxPunchBody = SDL_Rect{0, 0, 86, 109};
    SDL_Rect hitboxPunchArm = SDL_Rect{0,0, 40, 20 };

    stateHitBoxes["still"] = { hitboxStill };
    stateHitBoxes["walk"] = { hitboxWalk };
    stateHitBoxes["jump"] = { hitboxJump };
    stateHitBoxes["entering"] = { hitboxJump };
    stateHitBoxes["leaving"] = { hitboxJump };
    stateHitBoxes["crowchedDown"] = { hitboxCrowchedDown };
    stateHitBoxes["punch"] = { hitboxPunchBody, hitboxPunchArm };


    stateIterHitboxes = stateHitBoxes.find(currentState);
    hitboxes = stateIterHitboxes->second;
}


void CaptainAmericaHitboxManager::setHitboxes(string state, bool hFlip) {

    SDL_Rect currentHitbox = hitboxes[0];

    int x = currentHitbox.x;
    int y = currentHitbox.y;
    stateIterHitboxes = stateHitBoxes.find(state);

    if(state == "crowchedDown"){
        int aux = currentHitbox.h - stateIterHitboxes->second[0].h;
        y = y + aux;
    }

    if(currentState == "crowchedDown"){
        int aux = stateIterHitboxes->second[0].h - currentHitbox.h;
        y = y - aux;
    }

    if (state == "walk"){
        x = x + 30;
    }

    if(currentState == "walk"){
        x = x - 30;
    }

    currentState = state;
    if(state == "punch") {
        vector<SDL_Rect> hitboxes = stateIterHitboxes ->second;
        SDL_Rect body = hitboxes[0];
        SDL_Rect arm = hitboxes[1];

        body.x = x;
        body.y = y;

        arm.x = hFlip ? (body.x - arm.w) : (body.w + x);
        arm.y = body.y;

        hitboxes = { body, arm };

    } else {
        currentHitbox.x = x;
        currentHitbox.y = y;
    }
}

void CaptainAmericaHitboxManager::setInitialPos(int x, int y) {
    hitboxes[0].x = x + 26;
    hitboxes[0].y = y;
}


