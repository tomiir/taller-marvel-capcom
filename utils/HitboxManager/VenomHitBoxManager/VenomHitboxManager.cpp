//
// Created by arielpm on 30/05/19.
//

#include "VenomHitboxManager.h"

VenomHitboxManager::VenomHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxWalkBackward = SDL_Rect{668, 178, 158, 293};
    SDL_Rect hitboxWalkFoward = SDL_Rect{668, 178, 180, 293};
    SDL_Rect hitboxStill = SDL_Rect{673, 215, 218, 245};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{630, 298, 213, 168};
    SDL_Rect hitboxJump = SDL_Rect{608, 178, 218, 178};

    SDL_Rect hitboxStandKicked = SDL_Rect{623, 175, 195, 288};
    SDL_Rect hitboxDownKicked = SDL_Rect{630, 240, 195, 213};
    SDL_Rect hitboxAirKicked = SDL_Rect{630, 185, 218, 140};

    SDL_Rect hitboxStandGuard = SDL_Rect{568, 63, 330, 400};
    SDL_Rect hitboxDownGuard = SDL_Rect{570, 180, 320, 298};
    SDL_Rect hitboxAirGuard = SDL_Rect{605, 53, 328, 308};

    SDL_Rect hitboxWeakAirPunchBody = SDL_Rect{700, 170, 178, 155};
    SDL_Rect hitboxWeakAirPunchArm = SDL_Rect{875, 185, 205, 58};
    SDL_Rect hitboxWeakStandPunchBody = SDL_Rect{740, 265, 173, 210};
    SDL_Rect hitboxWeakStandPunchArm = SDL_Rect{913, 283, 205, 58};
    SDL_Rect hitboxWeakDownPunchBody = SDL_Rect{660, 330, 210, 130};
    SDL_Rect hitboxWeakDownPunchArm = SDL_Rect{870, 338, 205, 58};

    SDL_Rect hitboxStrongAirPunchBody = SDL_Rect{540, 15, 400, 393};
    SDL_Rect hitboxStrongStandPunchBody = SDL_Rect{605, 213, 220, 240};
    SDL_Rect hitboxStrongStandPunchArm = SDL_Rect{960, 225, 410, 130};
    SDL_Rect hitboxStrongDownPunchBody = SDL_Rect{605, 213, 220, 240};
    SDL_Rect hitboxStrongDownPunchArm = SDL_Rect{825, 268, 470, 130};

    SDL_Rect hitboxWeakAirKickBody = SDL_Rect{560, 150, 173, 198};
    SDL_Rect hitboxWeakAirKickLeg = SDL_Rect{733, 255, 220, 120};
    SDL_Rect hitboxWeakStandKickBody = SDL_Rect{560, 248, 173, 228};
    SDL_Rect hitboxWeakStandKickLeg = SDL_Rect{733, 355, 220, 120};
    SDL_Rect hitboxWeakDownKickBody = SDL_Rect{560, 280, 203, 195};
    SDL_Rect hitboxWeakDownKickLeg = SDL_Rect{763, 395, 203, 88};

    SDL_Rect hitboxStrongAirKickBody = SDL_Rect{628, 105, 180, 228};
    SDL_Rect hitboxStrongAirKickLeg = SDL_Rect{808, 185, 268, 178};
    SDL_Rect hitboxStrongStandKickBody = SDL_Rect{628, 220, 213, 243};
    SDL_Rect hitboxStrongStandKickLeg = SDL_Rect{840, 290, 203, 185};
    SDL_Rect hitboxStrongDownKickBody = SDL_Rect{605, 343, 238, 125};
    SDL_Rect hitboxStrongDownKickLeg = SDL_Rect{778, 298, 273, 70};

    SDL_Rect hitboxThrowing = SDL_Rect{623, 175, 320, 293};
    SDL_Rect hitboxGrab = SDL_Rect{723, 215, 210, 248};
    SDL_Rect hitboxNull = SDL_Rect{0, 0, 0, 0};


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
    stateHitBoxes["strongAirPunch"] = {hitboxStrongAirPunchBody};
    stateHitBoxes["strongAirKick"] = {hitboxStrongAirKickBody, hitboxStrongAirKickLeg};
    stateHitBoxes["strongDownPunch"] = {hitboxStrongDownPunchBody, hitboxStrongDownPunchArm};
    stateHitBoxes["strongDownKick"] = {hitboxStrongDownKickBody, hitboxStrongDownKickLeg};
    stateHitBoxes["throw"] = {hitboxThrowing};

    stateHitBoxes["grabLeft"] = {hitboxGrab};
    stateHitBoxes["grabRight"] = {hitboxGrab};
    stateHitBoxes["grabbed"] = {hitboxNull};
    stateHitBoxes["grabbedImpact"] = {hitboxNull};



    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;
}


void VenomHitboxManager::setInitialPosH(int x, int y, bool flip) {
    if(flip) currentHitboxes[0].x = x + 1400 - 673 - currentHitboxes[0].w; //Hitbox de still ubicado en x del sprite + ancho del sprite - distancia del hitbox - ancho hitbox
    else currentHitboxes[0].x = x + 673;
    currentHitboxes[0].y = y + 215;

}
