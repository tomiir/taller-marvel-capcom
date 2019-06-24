//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKAIRKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaWeakAirKickAnimation: public Animation {

public:
    CaptainAmericaWeakAirKickAnimation();
    ~CaptainAmericaWeakAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKAIRKICKANIMATION_H
