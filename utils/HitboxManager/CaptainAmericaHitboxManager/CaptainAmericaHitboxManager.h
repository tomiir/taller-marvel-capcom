//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAHITBOXMANAGER_H


#include "../HitboxManager.h"

class CaptainAmericaHitboxManager : public HitboxManager {

public:
    CaptainAmericaHitboxManager();
    ~CaptainAmericaHitboxManager() = default;
    void setInitialPosH(int x, int y, bool flip) override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAHITBOXMANAGER_H
