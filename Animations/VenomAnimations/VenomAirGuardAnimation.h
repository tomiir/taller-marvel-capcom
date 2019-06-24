//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMAIRGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMAIRGUARDANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomAirGuardAnimation: public Animation {

public:
    VenomAirGuardAnimation();
    ~VenomAirGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMAIRGUARDANIMATION_H
