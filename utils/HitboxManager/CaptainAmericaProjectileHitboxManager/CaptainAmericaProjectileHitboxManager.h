//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILEHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILEHITBOXMANAGER_H

#include "../HitboxManager.h"

class CaptainAmericaProjectileHitboxManager : public HitboxManager {

public:
    CaptainAmericaProjectileHitboxManager();
    ~CaptainAmericaProjectileHitboxManager() = default;
    void setInitialPosH(int x, int y, bool flip) override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPROJECTILEHITBOXMANAGER_H
