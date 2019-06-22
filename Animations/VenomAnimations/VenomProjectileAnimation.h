//
// Created by arielpm on 22/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMPROJECTILEANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMPROJECTILEANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class VenomProjectileAnimation: public Animation {

public:
    VenomProjectileAnimation();
    ~VenomProjectileAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_VENOMPROJECTILEANIMATION_H
