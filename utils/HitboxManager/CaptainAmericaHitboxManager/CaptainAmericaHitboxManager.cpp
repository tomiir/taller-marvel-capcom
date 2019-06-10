//
// Created by arielpm on 30/05/19.
//

#include "CaptainAmericaHitboxManager.h"

CaptainAmericaHitboxManager::CaptainAmericaHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 160, 277};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 130, 277};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 157, 215};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 162, 195};
    SDL_Rect hitboxPunchBody = SDL_Rect{0, 0, 160, 277};
    SDL_Rect hitboxPunchArm = SDL_Rect{0,0, 90, 40};

    stateHitBoxes["still"] = { hitboxStill };
    stateHitBoxes["walk"] = { hitboxWalk };
    stateHitBoxes["jump"] = { hitboxJump };
    stateHitBoxes["entering"] = { hitboxJump };
    stateHitBoxes["leaving"] = { hitboxJump };
    stateHitBoxes["crowchedDown"] = { hitboxCrowchedDown };
    stateHitBoxes["punch"] = { hitboxPunchBody, hitboxPunchArm };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void CaptainAmericaHitboxManager::setHitboxes(string newState, bool hFlip) {

    //Guarda la posicion del hitbox anterior
    SDL_Rect currentHitbox = currentHitboxes[0];
    int currentX = currentHitbox.x;
    int currentY = currentHitbox.y;

    //Busco el nuevo hitbox
    stateIterHitboxes = stateHitBoxes.find(newState);
    vector<SDL_Rect> newHitboxes = stateIterHitboxes->second;
    SDL_Rect newHitbox = newHitboxes[0];

    int difHeight =  abs(currentHitbox.h - newHitbox.h);

    if(newState == "crowchedDown") currentY += difHeight;
    if(currentState == "crowchedDown") currentY -= difHeight;


    //Esto es porque el sprite de capitan es bastante raro

    if(newState == "walk") currentX += 15;
    if(currentState == "walk") currentX -= 15;

    currentState = newState;

    if(currentState == "punch") {
        SDL_Rect body = newHitboxes[0];
        SDL_Rect arm = newHitboxes[1];

        body.x = currentX;
        body.y = currentY;

        arm.x = hFlip ? (body.x - arm.w) : (body.w + currentX);
        arm.y = body.y;

        currentHitboxes = { body, arm };
    } else {
        newHitbox.x = currentX;
        newHitbox.y = currentY;
        currentHitboxes = { newHitbox };
    }
//    currentHitboxes = newHitboxes;

}

void CaptainAmericaHitboxManager::setInitialPos(int x, int y) {
    currentHitboxes[0].x = x + 20;
    currentHitboxes[0].y = y;
}


