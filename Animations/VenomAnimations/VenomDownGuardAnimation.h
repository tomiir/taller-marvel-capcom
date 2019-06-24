//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMDOWNGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMDOWNGUARDANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomDownGuardAnimation: public Animation {

public:
    VenomDownGuardAnimation();
    ~VenomDownGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMDOWNGUARDANIMATION_H
