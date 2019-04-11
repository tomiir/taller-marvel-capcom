//
// Created by arielpm on 10/04/19.
//

#include <iostream>
#include "SpiderManSpriteManager.h"
#include "../../../Animations/SpiderMan/SpiderManStillAnimation.h"
#include "../../../Animations/SpiderMan/SpiderManWalkAnimation.h"
#include "../../../Animations/SpiderMan/SpiderManCrowchedDownAnimation.h"
#include "../../../Animations/SpiderMan/SpiderManJumpAnimation.h"


using namespace std;

void SpiderManSpriteManager::init(){


    animationMap["still"] = new SpiderManStillAnimation();
    animationMap["walk"] = new SpiderManWalkAnimation();
    animationMap["jump"] = new SpiderManJumpAnimation();
    animationMap["crowchedDown"] = new SpiderManCrowchedDownAnimation();
}

SpiderManSpriteManager::SpiderManSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}