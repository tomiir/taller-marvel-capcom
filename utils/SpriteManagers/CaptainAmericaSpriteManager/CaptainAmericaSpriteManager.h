//
// Created by fer on 07/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICASPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICASPRITEMANAGER_H

#include <iostream>
#include "../SpriteManager.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaStillAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWalkFowardAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaJumpAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaCrowchedDownAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaEnteringAnimation.h"
#include "../../../Animations/CaptainAmericaAnimations/CaptainAmericaWeakStandPunchAnimation.h"

class CaptainAmericaSpriteManager : public SpriteManager {


public:

    CaptainAmericaSpriteManager();
    ~CaptainAmericaSpriteManager() = default;

    void init() override ;

};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICASPRITEMANAGER_H
