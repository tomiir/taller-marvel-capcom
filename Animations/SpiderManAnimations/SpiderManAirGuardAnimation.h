//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANAIRGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANAIRGUARDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"

class SpiderManAirGuardAnimation: public Animation {

public:
    SpiderManAirGuardAnimation();
    ~SpiderManAirGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANAIRGUARDANIMATION_H
