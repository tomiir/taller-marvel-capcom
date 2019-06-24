//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILESPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILESPRITEMANAGER_H

#include <iostream>
#include "../SpriteManager.h"


class ChunLiProjectileSpriteManager : public SpriteManager {


public:

    ChunLiProjectileSpriteManager();
    ~ChunLiProjectileSpriteManager() = default;

    void init() override ;

};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILESPRITEMANAGER_H
