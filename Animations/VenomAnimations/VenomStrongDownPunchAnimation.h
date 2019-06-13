//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONDOWNPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONDOWNPUNCHANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongDownPunchAnimation: public Animation {

public:
    VenomStrongDownPunchAnimation();
    ~VenomStrongDownPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONDOWNPUNCHANIMATION_H
