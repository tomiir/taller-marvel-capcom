//
// Created by fer on 07/04/19.
//

#include "CaptainAmericaSpriteManager.h"

#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWalkFowardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaJumpAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaCrowchedDownAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaEnteringAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakStandPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakDownPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakAirPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongStandPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongDownPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongAirPunchAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakStandKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakDownKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakAirKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongStandKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongAirKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaDownKickedAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStandKickedAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaAirKickedAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaGrabAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaDownGuardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStrongDownKickAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaAirGuardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStandGuardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaThrowAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaGrabbedAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaGrabbedImpactAnimation.h"


using namespace std;

void CaptainAmericaSpriteManager::init(){


    animationMap["still"] = new CaptainAmericaStillAnimation();
    animationMap["walk"] = new CaptainAmericaWalkFowardAnimation();
    animationMap["jump"] = new CaptainAmericaJumpAnimation();
    animationMap["crowchedDown"] = new CaptainAmericaCrowchedDownAnimation();
    animationMap["entering"] = new CaptainAmericaEnteringAnimation();
    animationMap["weakStandPunch"] = new CaptainAmericaWeakStandPunchAnimation();
    animationMap["weakDownPunch"] = new CaptainAmericaWeakDownPunchAnimation();
    animationMap["weakAirPunch"] = new CaptainAmericaWeakAirPunchAnimation();
    animationMap["strongStandPunch"] = new CaptainAmericaStrongStandPunchAnimation();
    animationMap["strongDownPunch"] = new CaptainAmericaStrongDownPunchAnimation();
    animationMap["strongAirPunch"] = new CaptainAmericaStrongAirPunchAnimation();
    animationMap["weakStandKick"] = new CaptainAmericaWeakStandKickAnimation();
    animationMap["weakDownKick"] = new CaptainAmericaWeakDownKickAnimation();
    animationMap["weakAirKick"] = new CaptainAmericaWeakAirKickAnimation();
    animationMap["strongStandKick"] = new CaptainAmericaStrongStandKickAnimation();
    animationMap["strongDownKick"] = new CaptainAmericaStrongDownKickAnimation();
    animationMap["strongAirKick"] = new CaptainAmericaStrongAirKickAnimation();
    animationMap["downKicked"] = new CaptainAmericaDownKickedAnimation();
    animationMap["standKicked"] = new CaptainAmericaStandKickedAnimation();
    animationMap["airKicked"] = new CaptainAmericaAirKickedAnimation();
    animationMap["grab"] = new CaptainAmericaGrabAnimation();
    animationMap["downGuard"] = new CaptainAmericaDownGuardAnimation();
    animationMap["standGuard"] = new CaptainAmericaStandGuardAnimation();
    animationMap["airGuard"] = new CaptainAmericaAirGuardAnimation();
    animationMap["throw"] = new CaptainAmericaThrowAnimation();
    animationMap["grabbed"] = new CaptainAmericaGrabbedAnimation();
    animationMap["grabbedImpact"] = new CaptainAmericaGrabbedImpactAnimation();

}

CaptainAmericaSpriteManager::CaptainAmericaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
