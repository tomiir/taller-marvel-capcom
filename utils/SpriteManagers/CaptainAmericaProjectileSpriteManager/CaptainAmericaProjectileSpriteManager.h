//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILESPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILESPRITEMANAGER_H

#include <iostream>
#include "../SpriteManager.h"


class CaptainAmericaProjectileSpriteManager : public SpriteManager {


public:

    CaptainAmericaProjectileSpriteManager();
    ~CaptainAmericaProjectileSpriteManager() = default;

    void init() override ;

};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILESPRITEMANAGER_H
