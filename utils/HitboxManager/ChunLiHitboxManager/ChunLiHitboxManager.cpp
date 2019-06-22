//
// Created by arielpm on 30/05/19.
//

#include "ChunLiHitboxManager.h"

ChunLiHitboxManager::ChunLiHitboxManager() :  HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxWalkBackward = SDL_Rect{460, 238, 123, 208};
    SDL_Rect hitboxWalkFoward = SDL_Rect{485, 248, 123, 200};
    SDL_Rect hitboxStill = SDL_Rect{460, 238, 143, 210};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{470, 283, 143, 165};
    SDL_Rect hitboxJump = SDL_Rect{470, 215, 143, 183};

    SDL_Rect hitboxStandKicked = SDL_Rect{450, 245, 138, 205};
    SDL_Rect hitboxDownKicked = SDL_Rect{470, 275, 138, 168};
    SDL_Rect hitboxAirKicked = SDL_Rect{460, 213, 105, 168};

    SDL_Rect hitboxStandGuard = SDL_Rect{475, 228, 115, 213};
    SDL_Rect hitboxDownGuard = SDL_Rect{475, 275, 140, 165};
    SDL_Rect hitboxAirGuard = SDL_Rect{460, 205, 120, 165};

    SDL_Rect hitboxWeakAirPunchBody = SDL_Rect{493, 193, 120, 165};
    SDL_Rect hitboxWeakAirPunchArm = SDL_Rect{613, 255, 83, 50};
    SDL_Rect hitboxWeakStandPunchBody = SDL_Rect{493, 235, 120, 213};
    SDL_Rect hitboxWeakStandPunchArm = SDL_Rect{613, 255, 105, 33};
    SDL_Rect hitboxWeakDownPunchBody = SDL_Rect{493, 288, 120, 160};
    SDL_Rect hitboxWeakDownPunchArm = SDL_Rect{610, 315, 105, 33};

    SDL_Rect hitboxStrongAirPunchBody = SDL_Rect{480, 188, 105, 160};
    SDL_Rect hitboxStrongAirPunchArm = SDL_Rect{585, 235, 55, 113};
    SDL_Rect hitboxStrongStandPunchBody = SDL_Rect{558, 263, 93, 188};
    SDL_Rect hitboxStrongStandPunchArm = SDL_Rect{650, 253, 98, 63};
    SDL_Rect hitboxStrongDownPunchBody = SDL_Rect{558, 285, 128, 155};
    SDL_Rect hitboxStrongDownPunchArm = SDL_Rect{685, 310, 118, 38};

    SDL_Rect hitboxWeakAirKickBody = SDL_Rect{445, 218, 128, 130};
    SDL_Rect hitboxWeakAirKickLeg = SDL_Rect{573, 283, 153, 65};
    SDL_Rect hitboxWeakStandKickBody = SDL_Rect{488, 230, 85, 225};
    SDL_Rect hitboxWeakStandKickLeg = SDL_Rect{573, 230, 160, 83};
    SDL_Rect hitboxWeakDownKickBody = SDL_Rect{488, 338, 160, 60};
    SDL_Rect hitboxWeakDownKickLeg = SDL_Rect{603, 398, 160, 60};

    SDL_Rect hitboxStrongAirKickBody = SDL_Rect{473, 198, 130, 158};
    SDL_Rect hitboxStrongAirKickLeg = SDL_Rect{603, 220, 150, 70};
    SDL_Rect hitboxStrongStandKickBody = SDL_Rect{428, 300, 153, 148};
    SDL_Rect hitboxStrongStandKickLeg = SDL_Rect{505, 170, 108, 130};
    SDL_Rect hitboxStrongDownKickBody = SDL_Rect{460, 300, 153, 148};
    SDL_Rect hitboxStrongDownKickLeg = SDL_Rect{613, 293, 210, 60};

    SDL_Rect hitboxThrowing = SDL_Rect{455, 235, 150, 223};


    stateHitBoxes["still"] = { hitboxStill };
    stateHitBoxes["walk"] = { hitboxWalkFoward };
//    stateHitBoxes["walkFoward"] = { hitboxWalkFoward };
//    stateHitBoxes["walkBackward"] = {hitboxWalkBackward};
    stateHitBoxes["jump"] = { hitboxJump };
    stateHitBoxes["entering"] = { hitboxJump };
    stateHitBoxes["leaving"] = { hitboxJump };
    stateHitBoxes["crowchedDown"] = { hitboxCrowchedDown };
    stateHitBoxes["airGuard"] = { hitboxAirGuard };
    stateHitBoxes["standGuard"] = { hitboxStandGuard };
    stateHitBoxes["downGuard"] = { hitboxDownGuard };
    stateHitBoxes["airKicked"] = { hitboxAirKicked };
    stateHitBoxes["standKicked"] = { hitboxStandKicked };
    stateHitBoxes["downKicked"] = { hitboxDownKicked };

    stateHitBoxes["weakStandPunch"] = { hitboxWeakStandPunchBody, hitboxWeakStandPunchArm };
    stateHitBoxes["weakStandKick"] = {hitboxWeakStandKickBody, hitboxWeakStandKickLeg};
    stateHitBoxes["weakAirPunch"] = {hitboxWeakAirPunchBody, hitboxWeakAirPunchArm};
    stateHitBoxes["weakAirKick"] = {hitboxWeakAirKickBody, hitboxWeakAirKickLeg};
    stateHitBoxes["weakDownPunch"] = {hitboxWeakDownPunchBody, hitboxWeakDownPunchArm};
    stateHitBoxes["weakDownKick"] = {hitboxWeakDownKickBody, hitboxWeakDownKickLeg};
    stateHitBoxes["strongStandPunch"] = { hitboxStrongStandPunchBody, hitboxStrongStandPunchArm };
    stateHitBoxes["strongStandKick"] = {hitboxStrongStandKickBody, hitboxStrongStandKickLeg};
    stateHitBoxes["strongAirPunch"] = {hitboxStrongAirPunchBody, hitboxStrongAirPunchArm};
    stateHitBoxes["strongAirKick"] = {hitboxStrongAirKickBody, hitboxStrongAirKickLeg};
    stateHitBoxes["strongDownPunch"] = {hitboxStrongDownPunchBody, hitboxStrongDownPunchArm};
    stateHitBoxes["strongDownKick"] = {hitboxStrongDownKickBody, hitboxStrongDownKickLeg};
    stateHitBoxes["throw"] = {hitboxThrowing};


    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void ChunLiHitboxManager::setInitialPosH(int x, int y, bool flip) {
    if(flip) currentHitboxes[0].x = x + 1018 - 460 - currentHitboxes[0].w; //Hitbox de still ubicado en x del sprite + ancho del sprite - distancia del hitbox - ancho hitbox
    else currentHitboxes[0].x = x + 460;
    currentHitboxes[0].y = y + 238;
}
