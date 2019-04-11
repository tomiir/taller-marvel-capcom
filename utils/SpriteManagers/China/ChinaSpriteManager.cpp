//
// Created by fer on 07/04/19.
//

#include <iostream>
#include "ChinaSpriteManager.h"
#include "../../../Animations/China/ChinaStillAnimation.h"
#include "../../../Animations/China/ChinaWalkAnimation.h"

using namespace std;

void ChinaSpriteManager::init(){

    animationMap["still"] = new ChinaStillAnimation();
    animationMap["walk"] = new ChinaWalkAnimation();
//    animationMap.insert("jump", new ChinaJumpAnimation());
}

ChinaSpriteManager::ChinaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
