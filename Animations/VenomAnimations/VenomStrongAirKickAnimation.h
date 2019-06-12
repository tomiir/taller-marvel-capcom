//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongAirKickAnimation: public Animation {

public:
    VenomStrongAirKickAnimation();
    ~VenomStrongAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONGAIRKICKANIMATION_H
