//
// Created by arielpm on 10/04/19.
//

#include <iostream>
#include "SpiderManSpriteManager.h"
#include "../../../Animations/SpiderManStillAnimation.h"
#include "../../../Animations/SpiderManWalkAnimation.h"

using namespace std;

void SpiderManSpriteManager::init(){


    animationMap["still"] = new SpiderManStillAnimation();
    animationMap["walk"] = new SpiderManWalkAnimation();
//    animationMap.insert("jump", new CaptainAmericaJumpAnimation());
}

SpiderManSpriteManager::SpiderManSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}