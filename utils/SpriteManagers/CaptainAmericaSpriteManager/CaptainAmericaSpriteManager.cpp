//
// Created by fer on 07/04/19.
//

#include "CaptainAmericaSpriteManager.h"


using namespace std;

void CaptainAmericaSpriteManager::init(){


    animationMap["still"] = new CaptainAmericaStillAnimation();
    animationMap["walk"] = new CaptainAmericaWalkFowardAnimation();
    animationMap["jump"] = new CaptainAmericaJumpAnimation();
    animationMap["crowchedDown"] = new CaptainAmericaCrowchedDownAnimation();
    animationMap["entering"] = new CaptainAmericaEnteringAnimation();
    animationMap["punch"] = new CaptainAmericaPunchAnimation();

}

CaptainAmericaSpriteManager::CaptainAmericaSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
