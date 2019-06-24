//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKSTANDKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaWeakStandKickAnimation: public Animation {

public:
    CaptainAmericaWeakStandKickAnimation();
    ~CaptainAmericaWeakStandKickAnimation() = default;
    void init() override ;
};

#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKSTANDKICKANIMATION_H
