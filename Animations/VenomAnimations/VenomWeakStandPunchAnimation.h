//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class VenomWeakStandPunchAnimation: public Animation {

public:
    VenomWeakStandPunchAnimation();
    ~VenomWeakStandPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H
