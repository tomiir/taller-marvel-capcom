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


using namespace std;

void SpiderManSpriteManager::init(){


    animationMap["still"] = new SpiderManStillAnimation();
    animationMap["walk"] = new SpiderManWalkAnimation();
    animationMap["jump"] = new SpiderManJumpAnimation();
    animationMap["crowchedDown"] = new SpiderManCrowchedDownAnimation();
    animationMap["entering"] = new SpiderManEnteringAnimation();
    animationMap["punch"] = new SpiderManWeakStandPunchAnimation();
}

SpiderManSpriteManager::SpiderManSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}