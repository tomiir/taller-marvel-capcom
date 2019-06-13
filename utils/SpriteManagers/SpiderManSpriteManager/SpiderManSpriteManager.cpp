//
// Created by arielpm on 10/04/19.
//

#include <iostream>
#include "SpiderManSpriteManager.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStillAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWalkAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManCrowchedDownAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManJumpAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManEnteringAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakStandPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakDownPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakAirPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongStandPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongDownPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongAirPunchAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakStandKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakDownKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManWeakAirKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongStandKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongDownKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStrongAirKickAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManGrabAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManKickedAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManDownGuardAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManStandGuardAnimation.h"
#include "../../../Animations/SpiderManAnimations/SpiderManAirGuardAnimation.h"


using namespace std;

void SpiderManSpriteManager::init(){


    animationMap["still"] = new SpiderManStillAnimation();
    animationMap["walk"] = new SpiderManWalkAnimation();
    animationMap["jump"] = new SpiderManJumpAnimation();
    animationMap["crowchedDown"] = new SpiderManCrowchedDownAnimation();
    animationMap["entering"] = new SpiderManEnteringAnimation();
    animationMap["weakStandPunch"] = new SpiderManWeakStandPunchAnimation();
    animationMap["weakDownPunch"] = new SpiderManWeakDownPunchAnimation();
    animationMap["weakAirPunch"] = new SpiderManWeakAirPunchAnimation();
    animationMap["strongStandPunch"] = new SpiderManStrongStandPunchAnimation();
    animationMap["strongDownPunch"] = new SpiderManStrongDownPunchAnimation();
    animationMap["strongAirPunch"] = new SpiderManStrongAirPunchAnimation();
    animationMap["weakStandKick"] = new SpiderManWeakStandKickAnimation();
    animationMap["weakDownKick"] = new SpiderManWeakDownKickAnimation();
    animationMap["weakAirKick"] = new SpiderManWeakAirKickAnimation();
    animationMap["strongStandKick"] = new SpiderManStrongStandKickAnimation();
    animationMap["strongDownKick"] = new SpiderManStrongDownKickAnimation();
    animationMap["strongAirKick"] = new SpiderManStrongAirKickAnimation();
    animationMap["downKicked"] = new SpiderManKickedAnimation();
    animationMap["standKicked"] = new SpiderManKickedAnimation();
    animationMap["airKicked"] = new SpiderManKickedAnimation();
    animationMap["grab"] = new SpiderManGrabAnimation();
    animationMap["downGuard"] = new SpiderManDownGuardAnimation();
    animationMap["standGuard"] = new SpiderManStandGuardAnimation();
    animationMap["airGuard"] = new SpiderManAirGuardAnimation();
}

SpiderManSpriteManager::SpiderManSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}