//
// Created by arielpm on 22/06/19.
//

#include "SpiderManProjectileSpriteManager.h"
#include "../../../Animations/SpiderManAnimations/SpiderManProjectileAnimation.h"

using namespace std;

void SpiderManProjectileSpriteManager::init(){

    animationMap["flying"] = new SpiderManProjectileAnimation();

}

SpiderManProjectileSpriteManager::SpiderManProjectileSpriteManager() : SpriteManager(){

    init();
    state = "flying";
    actualAnimation = animationMap[state];
}