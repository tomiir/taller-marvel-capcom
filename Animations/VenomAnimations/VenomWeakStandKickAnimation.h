//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMWEAKKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMWEAKKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakStandKickAnimation: public Animation {

public:
    VenomWeakStandKickAnimation();
    ~VenomWeakStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMWEAKKICKANIMATION_H
