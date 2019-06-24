//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiStrongAirKickAnimation: public Animation {

public:
    ChunLiStrongAirKickAnimation();
    ~ChunLiStrongAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLISTRONGAIRKICKANIMATION_H
