//
// Created by arielpm on 30/05/19.
//

#include "SpiderManHitboxManager.h"

SpiderManHitboxManager::SpiderManHitboxManager() : HitboxManager(){

    currentState = "still";

    SDL_Rect hitboxWalkBackward = SDL_Rect{503, 345, 168, 198};
    SDL_Rect hitboxWalkFoward = SDL_Rect{503, 345,  168, 198};
    SDL_Rect hitboxStill = SDL_Rect{503, 375, 178, 153};
    SDL_Rect hitboxCrowchedDown = SDL_Rect{525, 425, 150, 103};
    SDL_Rect hitboxJump = SDL_Rect{480, 275, 190, 158};

    SDL_Rect hitboxStandKicked = SDL_Rect{468, 395, 148, 133};
    SDL_Rect hitboxDownKicked = SDL_Rect{488, 375, 145, 175};
    SDL_Rect hitboxAirKicked = SDL_Rect{468, 313, 148, 128};

    SDL_Rect hitboxStandGuard = SDL_Rect{445, 290, 220, 238};
    SDL_Rect hitboxDownGuard = SDL_Rect{473, 390, 220, 155};
    SDL_Rect hitboxAirGuard = SDL_Rect{498, 208, 195, 225};

    SDL_Rect hitboxWeakAirPunchBody = SDL_Rect{515, 255, 133, 143};
    SDL_Rect hitboxWeakAirPunchArm = SDL_Rect{615, 398, 80, 70};
    SDL_Rect hitboxWeakStandPunchBody = SDL_Rect{540, 358, 138, 168};
    SDL_Rect hitboxWeakStandPunchArm = SDL_Rect{678, 368, 133, 40};
    SDL_Rect hitboxWeakDownPunchBody = SDL_Rect{548, 430, 160, 113};
    SDL_Rect hitboxWeakDownPunchArm = SDL_Rect{695, 485, 143, 40};

    SDL_Rect hitboxStrongAirPunchBody = SDL_Rect{530, 270, 125, 190};
    SDL_Rect hitboxStrongAirPunchArm = SDL_Rect{655, 270, 133, 158};
    SDL_Rect hitboxStrongStandPunchBody = SDL_Rect{575, 285, 125, 190};
    SDL_Rect hitboxStrongStandPunchArm = SDL_Rect{700, 300, 180, 158};
    SDL_Rect hitboxStrongDownPunchBody = SDL_Rect{583, 428, 188, 113};
    SDL_Rect hitboxStrongDownPunchArm = SDL_Rect{738, 335, 138, 205};

    SDL_Rect hitboxWeakAirKickBody = SDL_Rect{498, 263, 150, 108};
    SDL_Rect hitboxWeakAirKickLeg = SDL_Rect{648, 320, 148, 103};
    SDL_Rect hitboxWeakStandKickBody = SDL_Rect{498, 335, 150, 208};
    SDL_Rect hitboxWeakStandKickLeg = SDL_Rect{648, 350, 193, 55};
    SDL_Rect hitboxWeakDownKickBody = SDL_Rect{538, 420, 110, 123};
    SDL_Rect hitboxWeakDownKickLeg = SDL_Rect{648, 455, 200, 55};

    SDL_Rect hitboxStrongAirKickBody = SDL_Rect{488, 240, 155, 155};
    SDL_Rect hitboxStrongAirKickLeg = SDL_Rect{643, 168, 123, 228};
    SDL_Rect hitboxStrongStandKickBody = SDL_Rect{510, 258, 150, 243};
    SDL_Rect hitboxStrongStandKickLeg = SDL_Rect{660, 258, 188, 200};
    SDL_Rect hitboxStrongDownKickBody = SDL_Rect{615, 383, 150, 155};
    SDL_Rect hitboxStrongDownKickLeg = SDL_Rect{765, 460, 260, 78};

    SDL_Rect hitboxThrowing = SDL_Rect{478, 358, 290, 193};
    SDL_Rect hitboxGrab = SDL_Rect{503, 345,  200, 198};
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
    stateHitBoxes["strongAirPunch"] = {hitboxStrongAirPunchBody, hitboxStrongAirPunchArm};
    stateHitBoxes["strongAirKick"] = {hitboxStrongAirKickBody, hitboxStrongAirKickLeg};
    stateHitBoxes["strongDownPunch"] = {hitboxStrongDownPunchBody, hitboxStrongDownPunchArm};
    stateHitBoxes["strongDownKick"] = {hitboxStrongDownKickBody, hitboxStrongDownKickLeg};
    stateHitBoxes["throw"] = {hitboxThrowing};

    stateHitBoxes["grab"] = {hitboxGrab};
    stateHitBoxes["grabbed"] = {hitboxNull};
    stateHitBoxes["grabbedImpact"] = {hitboxNull};

    stateIterHitboxes = stateHitBoxes.find(currentState);
    currentHitboxes = stateIterHitboxes->second;}


void SpiderManHitboxManager::setInitialPosH(int x, int y, bool flip) {
    if(flip) currentHitboxes[0].x = x + 1228 - 503 - currentHitboxes[0].w; //Hitbox de still ubicado en x del sprite + ancho del sprite - distancia del hitbox - ancho hitbox
    else currentHitboxes[0].x = x + 503;
    currentHitboxes[0].y = y + 375;
}
