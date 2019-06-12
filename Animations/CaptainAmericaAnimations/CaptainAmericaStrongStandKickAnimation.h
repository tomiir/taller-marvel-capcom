//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGSTANDKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaStrongStandKickAnimation: public Animation {

public:
    CaptainAmericaStrongStandKickAnimation();
    ~CaptainAmericaStrongStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGSTANDKICKANIMATION_H
