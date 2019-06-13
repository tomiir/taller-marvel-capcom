//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongStandKickAnimation: public Animation {

public:
    ChunLiStrongStandKickAnimation();
    ~ChunLiStrongStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGSTANDKICKANIMATION_H
