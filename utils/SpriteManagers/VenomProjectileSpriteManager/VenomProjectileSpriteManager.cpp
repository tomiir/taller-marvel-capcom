//
// Created by arielpm on 22/06/19.
//

#include "VenomProjectileSpriteManager.h"
#include "../../../Animations/VenomAnimations/VenomProjectileAnimation.h"

using namespace std;

void VenomProjectileSpriteManager::init(){

    animationMap["flying"] = new VenomProjectileAnimation();

}

VenomProjectileSpriteManager::VenomProjectileSpriteManager() : SpriteManager(){

    init();
    state = "flying";
    actualAnimation = animationMap[state];
}