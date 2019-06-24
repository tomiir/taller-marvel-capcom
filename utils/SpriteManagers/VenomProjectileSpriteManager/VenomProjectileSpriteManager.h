//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMPROJECTILESPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_VENOMPROJECTILESPRITEMANAGER_H

#include <iostream>
#include "../SpriteManager.h"


class VenomProjectileSpriteManager : public SpriteManager {


public:

    VenomProjectileSpriteManager();
    ~VenomProjectileSpriteManager() = default;

    void init() override ;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMPROJECTILESPRITEMANAGER_H
