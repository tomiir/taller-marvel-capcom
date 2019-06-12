//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONGDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONGDOWNKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongDownKickAnimation: public Animation {

public:
    VenomStrongDownKickAnimation();
    ~VenomStrongDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONGDOWNKICKANIMATION_H
