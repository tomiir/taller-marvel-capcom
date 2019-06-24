//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakDownKickAnimation: public Animation {

public:
    SpiderManWeakDownKickAnimation();
    ~SpiderManWeakDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKDOWNKICKANIMATION_H
