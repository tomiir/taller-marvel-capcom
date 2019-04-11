//
// Created by fer on 07/04/19.
//

#include <iostream>
#include "CaptainAmericaSpriteManager.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaWalkFowardAnimation.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaJumpAnimation.h"
#include "../../../Animations/CaptainAmerica/CaptainAmericaCrowchedDownAnimation.h"


using namespace std;

void CaptainAmericaSpriteManager::init(){


    animationMap["still"] = new CaptainAmericaStillAnimation();
    animationMap["walk"] = new CaptainAmericaWalkFowardAnimation();
    animationMap["jump"] = new CaptainAmericaJumpAnimation();
    animationMap["crowchedDown"] = new CaptainAmericaCrowchedDownAnimation();

}

CaptainAmericaSpriteManager::CaptainAmericaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
