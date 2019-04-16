//
// Created by arielpm on 13/04/19.
//

#include "ChunLiSpriteManager.h"
#include <iostream>
#include "../../../Animations/ChunLiAnimations/ChunLiStillAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiWalkFowardAnimation.h"
//#include "../../../Animations/ChunLiWalkBackwardsAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiJumpAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiCrowchedDownAnimation.h"
#include "../../../Animations/ChunLiAnimations/ChunLiEnteringAnimation.h"


using namespace std;

void ChunLiSpriteManager::init(){

    animationMap["still"] = new ChunLiStillAnimation();
    animationMap["walk"] = new ChunLiWalkFowardAnimation();
    animationMap["jump"] = new ChunLiJumpAnimation();
    animationMap["crowchedDown"] = new ChunLiCrowchedDownAnimation();
    animationMap["entering"] = new ChunLiEnteringAnimation();
}

ChunLiSpriteManager::ChunLiSpriteManager() : SpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}