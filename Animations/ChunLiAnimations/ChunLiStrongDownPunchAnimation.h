//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNPUNCHANIMATION_H


#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongDownPunchAnimation: public Animation {

public:
    ChunLiStrongDownPunchAnimation();
    ~ChunLiStrongDownPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNPUNCHANIMATION_H
