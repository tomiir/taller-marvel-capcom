//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANDOWNGUARDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANDOWNGUARDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"

class SpiderManDownGuardAnimation: public Animation {

public:
    SpiderManDownGuardAnimation();
    ~SpiderManDownGuardAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANDOWNGUARDANIMATION_H
