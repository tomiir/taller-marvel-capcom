//
// Created by fer on 09/04/19.
//

#include "VenomSpriteManager.h"
#include "../../../Animations/VenomAnimations/VenomStillAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWalkFowardAnimation.h"
#include "../../../Animations/VenomAnimations/VenomCrowchedDownAnimation.h"
#include "../../../Animations/VenomAnimations/VenomJumpAnimation.h"
#include "../../../Animations/VenomAnimations/VenomEnteringAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakStandPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakDownPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakAirPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongStandPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongDownPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongAirPunchAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakStandKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongStandKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongDownKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStrongAirKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomDownKickedAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStandKickedAnimation.h"
#include "../../../Animations/VenomAnimations/VenomAirGuardAnimation.h"
#include "../../../Animations/VenomAnimations/VenomGrabAnimation.h"
#include "../../../Animations/VenomAnimations/VenomDownGuardAnimation.h"
#include "../../../Animations/VenomAnimations/VenomStandGuardAnimation.h"
#include "../../../Animations/VenomAnimations/VenomAirKickedAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakDownKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWeakAirKickAnimation.h"
#include "../../../Animations/VenomAnimations/VenomThrowAnimation.h"


using namespace std;

void VenomSpriteManager::init(){

    animationMap["still"] = new VenomStillAnimation();
    animationMap["walk"] = new VenomWalkFowardAnimation();
    animationMap["jump"] = new VenomJumpAnimation();
    animationMap["crowchedDown"] = new VenomCrowchedDownAnimation();
    animationMap["entering"] = new VenomEnteringAnimation();
    animationMap["weakStandPunch"] = new VenomWeakStandPunchAnimation();
    animationMap["weakDownPunch"] = new VenomWeakDownPunchAnimation();
    animationMap["weakAirPunch"] = new VenomWeakAirPunchAnimation();
    animationMap["strongStandPunch"] = new VenomStrongStandPunchAnimation();
    animationMap["strongDownPunch"] = new VenomStrongDownPunchAnimation();
    animationMap["strongAirPunch"] = new VenomStrongAirPunchAnimation();
    animationMap["weakStandKick"] = new VenomWeakStandKickAnimation();
    animationMap["weakDownKick"] = new VenomWeakDownKickAnimation();
    animationMap["weakAirKick"] = new VenomWeakAirKickAnimation();
    animationMap["strongStandKick"] = new VenomStrongStandKickAnimation();
    animationMap["strongDownKick"] = new VenomStrongDownKickAnimation();
    animationMap["strongAirKick"] = new VenomStrongAirKickAnimation();
    animationMap["downKicked"] = new VenomDownKickedAnimation();
    animationMap["standKicked"] = new VenomStandKickedAnimation();
    animationMap["airKicked"] = new VenomAirKickedAnimation();
    animationMap["grab"] = new VenomGrabAnimation();
    animationMap["downGuard"] = new VenomDownGuardAnimation();
    animationMap["standGuard"] = new VenomStandGuardAnimation();
    animationMap["airGuard"] = new VenomAirGuardAnimation();
    animationMap["throw"] = new VenomThrowAnimation();

}

VenomSpriteManager::VenomSpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
