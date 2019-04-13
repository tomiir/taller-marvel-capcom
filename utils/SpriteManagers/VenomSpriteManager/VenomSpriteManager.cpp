//
// Created by fer on 09/04/19.
//

#include "VenomSpriteManager.h"
#include "../../../Animations/VenomStillAnimation.h"
#include "../../../Animations/VenomWalkFowardAnimation.h"
#include "../../../Animations/VenomCrowchedDownAnimation.h"
#include "../../../Animations/VenomJumpAnimation.h"
#include "../../../Animations/VenomEnteringAnimation.h"

using namespace std;

void VenomSpriteManager::init(){

    animationMap["still"] = new VenomStillAnimation();
    animationMap["walk"] = new VenomWalkFowardAnimation();
    animationMap["jump"] = new VenomJumpAnimation();
    animationMap["crowchedDown"] = new VenomCrowchedDownAnimation();
    animationMap["entering"] = new VenomEnteringAnimation();

}

VenomSpriteManager::VenomSpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
