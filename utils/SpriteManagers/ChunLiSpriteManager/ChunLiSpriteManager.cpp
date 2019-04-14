//
// Created by arielpm on 13/04/19.
//

#include "ChunLiSpriteManager.h"
#include <iostream>
#include "../../../Animations//ChunLiStillAnimation.h"
#include "../../../Animations/ChunLiWalkFowardAnimation.h"
//#include "../../../Animations/ChunLiWalkBackwardsAnimation.h"
#include "../../../Animations/ChunLiJumpAnimation.h"
#include "../../../Animations/ChunLiCrowchedDownAnimation.h"
#include "../../../Animations/ChunLiEnteringAnimation.h"


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