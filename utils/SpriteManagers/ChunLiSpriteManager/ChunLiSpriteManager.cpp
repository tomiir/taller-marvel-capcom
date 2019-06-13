//
// Created by arielpm on 13/04/19.
//

#include "ChunLiSpriteManager.h"
#include <iostream>

#include "../../../Animations/ChunLiAnimations/ChunLiStillAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWalkFowardAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiJumpAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiCrowchedDownAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiEnteringAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakStandPunchAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakDownPunchAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakAirPunchAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongStandPunchAnimaiton.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongDownPunchAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongAirPunchAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakStandKickAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakDownKickAnimartion.h"
#include "../../../Animations/ChunLiAnimations/ChunLiDownGuardAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongStandKickAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongDownKickAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStrongAirKickAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiDownKickedAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStandKickedAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiAirKickedAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiGrabAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiStandGuardAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiAirGuardAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWeakAirKickAnimation.h"


using namespace std;

void ChunLiSpriteManager::init(){

    animationMap["still"] = new ChunLiStillAnimation();
    animationMap["walk"] = new ChunLiWalkFowardAnimation();
    animationMap["jump"] = new ChunLiJumpAnimation();
    animationMap["crowchedDown"] = new ChunLiCrowchedDownAnimation();
    animationMap["entering"] = new ChunLiEnteringAnimation();
    animationMap["weakStandPunch"] = new ChunLiWeakStandPunchAnimation();
    animationMap["weakDownPunch"] = new ChunLiWeakDownPunchAnimation();
    animationMap["weakAirPunch"] = new ChunLiWeakAirPunchAnimation();
    animationMap["strongStandPunch"] = new ChunLiStrongStandPunchAnimation();
    animationMap["strongDownPunch"] = new ChunLiStrongDownPunchAnimation();
    animationMap["strongAirPunch"] = new ChunLiStrongAirPunchAnimation();
    animationMap["weakStandKick"] = new ChunLiWeakStandKickAnimation();
    animationMap["weakDownKick"] = new ChunLiWeakDownKickAnimation();
    animationMap["weakAirKick"] = new ChunLiWeakAirKickAnimation();
    animationMap["strongStandKick"] = new ChunLiStrongStandKickAnimation();
    animationMap["strongDownKick"] = new ChunLiStrongDownKickAnimation();
    animationMap["strongAirKick"] = new ChunLiStrongAirKickAnimation();
    animationMap["downKicked"] = new ChunLiDownKickedAnimation();
    animationMap["standKicked"] = new ChunLiStandKickedAnimation();
    animationMap["airKicked"] = new ChunLiAirKickedAnimation();
    animationMap["grab"] = new ChunLiGrabAnimation();
    animationMap["downGuard"] = new ChunLiDownGuardAnimation();
    animationMap["standGuard"] = new ChunLiStandGuardAnimation();
    animationMap["airGuard"] = new ChunLiAirGuardAnimation();
}

ChunLiSpriteManager::ChunLiSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}