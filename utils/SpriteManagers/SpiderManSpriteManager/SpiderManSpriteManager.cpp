//
// Created by arielpm on 10/04/19.
//

#include <iostream>
#include "SpiderManSpriteManager.h"
#include "../../../Animations/SpiderManStillAnimation.h"
#include "../../../Animations/SpiderManWalkAnimation.h"
#include "../../../Animations/SpiderManCrowchedDownAnimation.h"
#include "../../../Animations/SpiderManJumpAnimation.h"
#include "../../../Animations/SpiderManEnteringAnimation.h"


using namespace std;

void SpiderManSpriteManager::init(){


    animationMap["still"] = new SpiderManStillAnimation();
    animationMap["walk"] = new SpiderManWalkAnimation();
    animationMap["jump"] = new SpiderManJumpAnimation();
    animationMap["crowchedDown"] = new SpiderManCrowchedDownAnimation();
    animationMap["entering"] = new SpiderManEnteringAnimation();
}

SpiderManSpriteManager::SpiderManSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}