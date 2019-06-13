//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNKICKANIMATION_H


#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongDownKickAnimation: public Animation {

public:
    ChunLiStrongDownKickAnimation();
    ~ChunLiStrongDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGDOWNKICKANIMATION_H
