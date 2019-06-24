//
// Created by arielpm on 14/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMWEAKAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMWEAKAIRKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakAirKickAnimation: public Animation {

public:
    VenomWeakAirKickAnimation();
    ~VenomWeakAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMWEAKAIRKICKANIMATION_H
