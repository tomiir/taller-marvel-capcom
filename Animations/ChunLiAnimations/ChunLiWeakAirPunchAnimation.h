//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRPUNCHANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakAirPunchAnimation: public Animation {

public:
    ChunLiWeakAirPunchAnimation();
    ~ChunLiWeakAirPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRPUNCHANIMATION_H
