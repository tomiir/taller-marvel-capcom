//
// Created by fer on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSPRITEMANAGER_H
#define TALLER_MARVEL_CAPCOM_VENOMSPRITEMANAGER_H


#include "../SpriteManager.h"


class VenomSpriteManager : public SpriteManager{

public:
    VenomSpriteManager();
    ~VenomSpriteManager() = default;
    void init() override;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMSPRITEMANAGER_H
