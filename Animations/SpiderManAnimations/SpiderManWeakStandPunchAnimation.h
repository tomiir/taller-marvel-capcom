//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDPUNCHANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakStandPunchAnimation: public Animation {

public:
    SpiderManWeakStandPunchAnimation();
    ~SpiderManWeakStandPunchAnimation() = default;
    void init() override ;
};



#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDPUNCHANIMATION_H


