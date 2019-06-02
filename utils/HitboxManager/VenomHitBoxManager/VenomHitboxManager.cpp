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
    SDL_Rect hitboxPunchBody = SDL_Rect{0, 0, 62, 74};
    SDL_Rect hitboxPunchArm = SDL_Rect{0,0, 86, 28 };


    stateHitBoxes["still"] = { hitboxStill };
    stateHitBoxes["walk"] = { hitboxWalk };
    stateHitBoxes["jump"] = { hitboxJump };
    stateHitBoxes["entering"] = { hitboxJump };
    stateHitBoxes["leaving"] = { hitboxJump };
    stateHitBoxes["crowchedDown"] = { hitboxCrowchedDown };
    stateHitBoxes["punch"] = { hitboxPunchBody, hitboxPunchArm  };

    currentHitboxes = { hitboxStill };
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
        currentX -= 65;
    }
    if(currentState == "crowchedDown"){
        currentY -= difHeight;
        currentX += 65;
    }

    //Esto es porque el sprite de venom es bastante raro
    if(newState == "walk") currentY -= difHeight;
    if(currentState == "walk") currentY += difHeight;

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

void VenomHitboxManager::setInitialPos(int x, int y) {
    currentHitboxes[0].x = x + 65;
    currentHitboxes[0].y = y + 65;
}
