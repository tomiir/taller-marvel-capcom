//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGSTANDKICKANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManStrongStandKickAnimation: public Animation {

public:
    SpiderManStrongStandKickAnimation();
    ~SpiderManStrongStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGSTANDKICKANIMATION_H
