//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRPUNCH_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakAirPunchAnimation: public Animation {

public:
    SpiderManWeakAirPunchAnimation();
    ~SpiderManWeakAirPunchAnimation() = default;
    void init() override ;
};

#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRPUNCH_H
