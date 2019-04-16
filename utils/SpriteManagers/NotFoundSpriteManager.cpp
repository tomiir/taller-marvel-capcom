//
// Created by feeer on 15/4/2019.
//

#include "NotFoundSpriteManager.h"
#include "../../Animations/NotFoundAnimation.h"

void NotFoundSpriteManager::init() {


    animationMap["still"] = new NotFoundAnimation();
    animationMap["walk"] = new NotFoundAnimation();
    animationMap["jump"] = new NotFoundAnimation();
    animationMap["crowchedDown"] = new NotFoundAnimation();
    animationMap["entering"] = new NotFoundAnimation();
}

NotFoundSpriteManager::NotFoundSpriteManager() : SpriteManager(){

        init();
        state = "still";
        actualAnimation = animationMap[state];
    }
