//
// Created by fer on 09/04/19.
//

#include "VenomSpriteManager.h"
#include "../../../Animations/VenomStillAnimation.h"
#include "../../../Animations/VenomWalkFowardAnimation.h"

using namespace std;

void VenomSpriteManager::init(){

    animationMap["still"] = new VenomStillAnimation();
    animationMap["walk"] = new VenomWalkFowardAnimation();

}

VenomSpriteManager::VenomSpriteManager(){

    init();
    state = "still";
    actualAnimation = animationMap[state];
}
