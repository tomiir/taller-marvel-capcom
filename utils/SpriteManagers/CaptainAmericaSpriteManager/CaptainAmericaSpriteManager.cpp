//
// Created by fer on 07/04/19.
//

#include <iostream>
#include "CaptainAmericaSpriteManager.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaWalkAnimation.h"

using namespace std;

void CaptainAmericaSpriteManager::init(){


    animationMap["still"] = new ChinaStillAnimation();
    animationMap["walk"] = new CaptainAmericaWalkAnimation();
//    animationMap.insert("jump", new CaptainAmericaJumpAnimation());
}

CaptainAmericaSpriteManager::CaptainAmericaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
