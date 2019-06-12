//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGDOWNKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaStrongDownKickAnimation: public Animation {

public:
    CaptainAmericaStrongDownKickAnimation();
    ~CaptainAmericaStrongDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGDOWNKICKANIMATION_H
