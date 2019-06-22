//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMPROJECTILEHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_VENOMPROJECTILEHITBOXMANAGER_H

#include "../HitboxManager.h"

class VenomProjectileHitboxManager : public HitboxManager {

public:
    VenomProjectileHitboxManager();
    ~VenomProjectileHitboxManager() = default;
    void setInitialPosH(int x, int y, bool flip) override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMPROJECTILEHITBOXMANAGER_H
