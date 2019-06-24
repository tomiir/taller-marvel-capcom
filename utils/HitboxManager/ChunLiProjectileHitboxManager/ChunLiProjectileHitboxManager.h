//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILEHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILEHITBOXMANAGER_H


#include "../HitboxManager.h"

class ChunLiProjectileHitboxManager : public HitboxManager {

public:
    ChunLiProjectileHitboxManager();
    ~ChunLiProjectileHitboxManager() = default;
    void setInitialPosH(int x, int y, bool flip) override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIPROJECTILEHITBOXMANAGER_H
