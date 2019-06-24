//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDPUNCHANIMAITON_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDPUNCHANIMAITON_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongStandPunchAnimation: public Animation {

public:
    ChunLiStrongStandPunchAnimation();
    ~ChunLiStrongStandPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDPUNCHANIMAITON_H
