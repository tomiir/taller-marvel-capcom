//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRKICKANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManWeakAirKickAnimation: public Animation {

public:
    SpiderManWeakAirKickAnimation();
    ~SpiderManWeakAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWEAKAIRKICKANIMATION_H
