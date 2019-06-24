//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKDOWNKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaWeakDownKickAnimation: public Animation {

public:
    CaptainAmericaWeakDownKickAnimation();
    ~CaptainAmericaWeakDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWEAKDOWNKICKANIMATION_H
