//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDKICKANIMATION_H



#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakStandKickAnimation: public Animation {

public:
    SpiderManWeakStandKickAnimation();
    ~SpiderManWeakStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKSTANDKICKANIMATION_H
