//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDPUNCHANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class VenomStrongStandPunchAnimation: public Animation {

public:
    VenomStrongStandPunchAnimation();
    ~VenomStrongStandPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMSTRONGSTANDPUNCHANIMATION_H
