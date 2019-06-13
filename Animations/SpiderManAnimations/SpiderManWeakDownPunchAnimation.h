//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakDownPunchAnimation: public Animation {

public:
    SpiderManWeakDownPunchAnimation();
    ~SpiderManWeakDownPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNPUNCHANIMATION_H
