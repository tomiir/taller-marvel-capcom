//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILEHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILEHITBOXMANAGER_H

#include "../HitboxManager.h"

class SpiderManProjectileHitboxManager : public HitboxManager {

public:
    SpiderManProjectileHitboxManager();
    ~SpiderManProjectileHitboxManager() = default;
    void setInitialPosH(int x, int y, bool flip) override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANPROJECTILEHITBOXMANAGER_H
