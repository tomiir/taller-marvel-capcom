//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGDOWNKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManStrongDownKickAnimation: public Animation {

public:
    SpiderManStrongDownKickAnimation();
    ~SpiderManStrongDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGDOWNKICKANIMATION_H
