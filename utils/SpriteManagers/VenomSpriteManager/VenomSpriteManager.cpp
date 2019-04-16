//
// Created by fer on 09/04/19.
//

#include "VenomSpriteManager.h"
#include "../../../Animations/VenomAnimations/VenomStillAnimation.h"
#include "../../../Animations/VenomAnimations/VenomWalkFowardAnimation.h"
#include "../../../Animations/VenomAnimations/VenomCrowchedDownAnimation.h"
#include "../../../Animations/VenomAnimations/VenomJumpAnimation.h"
#include "../../../Animations/VenomAnimations/VenomEnteringAnimation.h"

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
