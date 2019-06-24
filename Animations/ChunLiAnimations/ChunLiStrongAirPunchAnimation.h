//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRPUNCHANIMATION_H


#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongAirPunchAnimation: public Animation {

public:
    ChunLiStrongAirPunchAnimation();
    ~ChunLiStrongAirPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRPUNCHANIMATION_H
