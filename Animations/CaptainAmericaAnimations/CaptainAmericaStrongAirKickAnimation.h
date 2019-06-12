//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGAIRKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaStrongAirKickAnimation: public Animation {

public:
    CaptainAmericaStrongAirKickAnimation();
    ~CaptainAmericaStrongAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICASTRONGAIRKICKANIMATION_H
