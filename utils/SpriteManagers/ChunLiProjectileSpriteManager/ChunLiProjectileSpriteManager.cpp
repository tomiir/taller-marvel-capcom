//
// Created by arielpm on 22/06/19.
//

#include "ChunLiProjectileSpriteManager.h"
#include "../../../Animations/ChunLiAnimations/ChunLiProjectileAnimation.h"

using namespace std;

void ChunLiProjectileSpriteManager::init(){

    animationMap["flying"] = new ChunLiProjectileAnimation();

}

ChunLiProjectileSpriteManager::ChunLiProjectileSpriteManager() : SpriteManager(){

    init();
    state = "flying";
    actualAnimation = animationMap[state];
}