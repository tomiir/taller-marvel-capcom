//
// Created by trocchi on 6/1/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPUNCHANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>

class CaptainAmericaWeakStandPunchAnimation: public Animation {

public:
    CaptainAmericaWeakStandPunchAnimation();
    ~CaptainAmericaWeakStandPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAPUNCHANIMATION_H
