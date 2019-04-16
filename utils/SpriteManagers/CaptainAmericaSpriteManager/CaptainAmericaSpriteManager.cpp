//
// Created by fer on 07/04/19.
//

#include <iostream>
#include "CaptainAmericaSpriteManager.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWalkFowardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaJumpAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaCrowchedDownAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaEnteringAnimation.h"


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
