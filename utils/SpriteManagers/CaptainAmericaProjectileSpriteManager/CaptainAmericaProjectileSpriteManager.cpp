//
// Created by arielpm on 22/06/19.
//

#include "CaptainAmericaProjectileSpriteManager.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaProjectileAnimation.h"

using namespace std;

void CaptainAmericaProjectileSpriteManager::init(){

    animationMap["flying"] = new CaptainAmericaProjectileAnimation();

}

CaptainAmericaProjectileSpriteManager::CaptainAmericaProjectileSpriteManager() : SpriteManager(){

    init();
    state = "flying";
    actualAnimation = animationMap[state];
}