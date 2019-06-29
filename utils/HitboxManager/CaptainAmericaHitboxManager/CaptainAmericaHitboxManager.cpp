//
// Created by arielpm on 30/05/19.
//

#include "CaptainAmericaHitboxManager.h"

CaptainAmericaHitboxManager::CaptainAmericaHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxWalkBackward = SDL_Rect{255, 200, 140, 293};
    SDL_Rect hitboxWalkFoward = SDL_Rect{273, 200, 123, 278};
    SDL_Rect hitboxStill = SDL_Rect{273, 200, 150, 260};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{260, 280, 183, 185};
    SDL_Rect hitboxJump = SDL_Rect{260, 200, 130, 203 };

    SDL_Rect hitboxStandKicked = SDL_Rect{250, 205, 175, 260};
    SDL_Rect hitboxDownKicked = SDL_Rect{238, 235, 185, 203};
    SDL_Rect hitboxAirKicked = SDL_Rect{218, 235, 185, 203};

    SDL_Rect hitboxStandGuard = SDL_Rect{243, 215, 178, 263};
    SDL_Rect hitboxDownGuard = SDL_Rect{243, 273, 168, 205};
    SDL_Rect hitboxAirGuard = SDL_Rect{263, 200, 160, 170};

    SDL_Rect hitboxWeakAirPunchBody = SDL_Rect{293, 158, 148, 223};
    SDL_Rect hitboxWeakAirPunchArm = SDL_Rect{440, 278, 83, 120};
    SDL_Rect hitboxWeakStandPunchBody = SDL_Rect{273, 200, 168, 260};
    SDL_Rect hitboxWeakStandPunchArm = SDL_Rect{440, 213, 153, 58};
    SDL_Rect hitboxWeakDownPunchBody = SDL_Rect{300, 280, 168, 198};
    SDL_Rect hitboxWeakDownPunchArm = SDL_Rect{468, 280, 135, 100};

    SDL_Rect hitboxStrongAirPunchBody = SDL_Rect{320, 230, 228, 125};
    SDL_Rect hitboxStrongAirPunchArm1 = SDL_Rect{625, 163, 115, 240};
    SDL_Rect hitboxStrongAirPunchArm2 = SDL_Rect{370, 38, 255, 483};
    SDL_Rect hitboxStrongStandPunchBody = SDL_Rect{290, 273, 228, 205};
    SDL_Rect hitboxStrongStandPunchArm1 = SDL_Rect{518, 273, 210, 205};
    SDL_Rect hitboxStrongStandPunchArm2 = SDL_Rect{223, 183, 403, 90};
    SDL_Rect hitboxStrongDownPunchBody = SDL_Rect{290, 328, 228, 150};
    SDL_Rect hitboxStrongDownPunchArm = SDL_Rect{443, 223, 190, 255};

    SDL_Rect hitboxWeakAirKickBody = SDL_Rect{285, 180, 178, 160};
    SDL_Rect hitboxWeakAirKickLeg = SDL_Rect{463, 293, 153, 80};
    SDL_Rect hitboxWeakStandKickBody = SDL_Rect{305, 185, 133, 278};
    SDL_Rect hitboxWeakStandKickLeg = SDL_Rect{438, 288, 135, 163};
    SDL_Rect hitboxWeakDownKickBody = SDL_Rect{223, 308, 178, 160};
    SDL_Rect hitboxWeakDownKickLeg = SDL_Rect{400, 405, 165, 73};

    SDL_Rect hitboxStrongAirKickBody = SDL_Rect{280, 185, 123, 185};
    SDL_Rect hitboxStrongAirKickLeg = SDL_Rect{403, 173, 188, 70};
    SDL_Rect hitboxStrongStandKickBody = SDL_Rect{358, 173, 140, 305};
    SDL_Rect hitboxStrongStandKickLeg = SDL_Rect{498, 200, 168, 88};
    SDL_Rect hitboxStrongDownKickBody = SDL_Rect{345, 288, 133, 190};
    SDL_Rect hitboxStrongDownKickLeg = SDL_Rect{478, 398, 208, 65};

    SDL_Rect hitboxThrowing = SDL_Rect{273, 233, 448, 233};
    SDL_Rect hitboxGrab = SDL_Rect{310, 188, 175, 278};
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
    stateHitBoxes["strongStandPunch"] = { hitboxStrongStandPunchBody, hitboxStrongStandPunchArm1, hitboxStrongStandPunchArm2 };
    stateHitBoxes["strongStandKick"] = {hitboxStrongStandKickBody, hitboxStrongStandKickLeg};
    stateHitBoxes["strongAirPunch"] = {hitboxStrongAirPunchBody, hitboxStrongAirPunchArm1, hitboxStrongAirPunchArm2};
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


void CaptainAmericaHitboxManager::setInitialPosH(int x, int y, bool flip) {
    if(flip){
        currentHitboxes[0].x = x + 805 - 273 - currentHitboxes[0].w; //Hitbox de still ubicado en x del sprite + ancho del sprite - distancia del hitbox - ancho hitbox
    }
    else currentHitboxes[0].x = x + 273;
    currentHitboxes[0].y = y + 200;
}


