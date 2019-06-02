//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class VenomPunchAnimation: public Animation {

public:
    VenomPunchAnimation();
    ~VenomPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMPUNCHANIMATION_H
