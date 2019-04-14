//
// Created by fer on 07/04/19.
//

#include <iostream>
#include "CaptainAmericaSpriteManager.h"
#include "../../../Animations/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmericaWalkFowardAnimation.h"
#include "../../../Animations/CaptainAmericaJumpAnimation.h"
#include "../../../Animations/CaptainAmericaCrowchedDownAnimation.h"
#include "../../../Animations/CaptainAmericaEnteringAnimation.h"


using namespace std;

void CaptainAmericaSpriteManager::init(){


    animationMap["still"] = new CaptainAmericaStillAnimation();
    animationMap["walk"] = new CaptainAmericaWalkFowardAnimation();
    animationMap["jump"] = new CaptainAmericaJumpAnimation();
    animationMap["crowchedDown"] = new CaptainAmericaCrowchedDownAnimation();
    animationMap["entering"] = new CaptainAmericaEnteringAnimation();

}

CaptainAmericaSpriteManager::CaptainAmericaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
