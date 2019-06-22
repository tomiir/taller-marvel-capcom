//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILESPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILESPRITEMANAGER_H

#include <iostream>
#include "../SpriteManager.h"


class SpiderManProjectileSpriteManager : public SpriteManager {


public:

    SpiderManProjectileSpriteManager();
    ~SpiderManProjectileSpriteManager() = default;

    void init() override ;

};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILESPRITEMANAGER_H
