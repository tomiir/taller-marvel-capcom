//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMWEAKAIRPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMWEAKAIRPUNCHANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakAirPunchAnimation: public Animation {

public:
    VenomWeakAirPunchAnimation();
    ~VenomWeakAirPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMWEAKAIRPUNCHANIMATION_H
