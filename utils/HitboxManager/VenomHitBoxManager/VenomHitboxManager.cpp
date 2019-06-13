//
// Created by arielpm on 30/05/19.
//

#include "VenomHitboxManager.h"

VenomHitboxManager::VenomHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxStill = SDL_Rect{0, 0, 310, 250};
    SDL_Rect hitboxWalk = SDL_Rect{0, 0, 270, 295};
    SDL_Rect hitboxJump = SDL_Rect{0, 0, 295, 170};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{0, 0, 250, 200};
    SDL_Rect hitboxPunchBody = SDL_Rect{0, 0, 310, 250};
    SDL_Rect hitboxPunchArm = SDL_Rect{0,0, 230, 70};


    stateHitBoxes["still"] = { hitboxStill };
    stateHitBoxes["walk"] = { hitboxWalk };
    stateHitBoxes["jump"] = { hitboxJump };
    stateHitBoxes["entering"] = { hitboxJump };
    stateHitBoxes["leaving"] = { hitboxJump };
    stateHitBoxes["crowchedDown"] = { hitboxCrowchedDown };
    stateHitBoxes["weakStandPunch"] = { hitboxPunchBody, hitboxPunchArm  };

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void VenomHitboxManager::setHitboxes(string newState, bool hFlip) {

    //Guarda la posicion del hitbox anterior
    SDL_Rect currentHitbox = currentHitboxes[0];
    int currentX = currentHitbox.x;
    int currentY = currentHitbox.y;

    //Busco el nuevo hitbox
    stateIterHitboxes = stateHitBoxes.find(newState);
    vector<SDL_Rect> newHitboxes = stateIterHitboxes->second;
    SDL_Rect newHitbox = newHitboxes[0];

    int difHeight =  abs(currentHitbox.h - newHitbox.h);

    if(newState == "crowchedDown") {
        currentY += difHeight;
        currentX += 20;
    }
    if(currentState == "crowchedDown"){
        currentY -= difHeight;
        currentX -= 20;
    }

    //Esto es porque el sprite de venom es bastante raro
    if(newState == "walk") currentY -= difHeight;
    if(currentState == "walk") currentY += difHeight;

    currentState = newState;

    if(currentState == "weakStandPunch") {
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

void VenomHitboxManager::setInitialPos(int x, int y) {
    currentHitboxes[0].x = x;
    currentHitboxes[0].y = y;
}
