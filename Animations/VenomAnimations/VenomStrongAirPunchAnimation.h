//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRPUNCH_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongAirPunchAnimation: public Animation {

public:
    VenomStrongAirPunchAnimation();
    ~VenomStrongAirPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRPUNCH_H
