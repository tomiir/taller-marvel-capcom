//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTANDGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTANDGUARDANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomStandGuardAnimation: public Animation {

public:
    VenomStandGuardAnimation();
    ~VenomStandGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTANDGUARDANIMATION_H
