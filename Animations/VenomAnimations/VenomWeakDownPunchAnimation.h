//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNPUNCHANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakDownPunchAnimation: public Animation {

public:
    VenomWeakDownPunchAnimation();
    ~VenomWeakDownPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNPUNCHANIMATION_H
