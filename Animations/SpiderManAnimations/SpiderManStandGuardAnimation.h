//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANSTANDGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANSTANDGUARDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"

class SpiderManStandGuardAnimation: public Animation {

public:
    SpiderManStandGuardAnimation();
    ~SpiderManStandGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANSTANDGUARDANIMATION_H
