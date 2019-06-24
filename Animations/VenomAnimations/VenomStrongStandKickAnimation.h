//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongStandKickAnimation: public Animation {

public:
    VenomStrongStandKickAnimation();
    ~VenomStrongStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDKICKANIMATION_H
