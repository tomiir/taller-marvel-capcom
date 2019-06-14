//
// Created by arielpm on 14/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakDownKickAnimation: public Animation {

public:
    VenomWeakDownKickAnimation();
    ~VenomWeakDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMWEAKDOWNKICKANIMATION_H
