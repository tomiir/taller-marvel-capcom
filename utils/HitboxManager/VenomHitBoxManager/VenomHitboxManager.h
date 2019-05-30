//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMHITBOXMANAGER_H
#define TALLER_MARVEL_CAPCOM_VENOMHITBOXMANAGER_H


#include "../HitboxManager.h"

class VenomHitboxManager : public HitboxManager{

public:
    VenomHitboxManager();
    ~VenomHitboxManager() = default;

    void setHitbox(string state) override ;

    void setInitialPos(int x, int y) override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMHITBOXMANAGER_H
