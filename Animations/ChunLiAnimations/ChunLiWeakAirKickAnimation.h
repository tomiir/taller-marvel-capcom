//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakAirKickAnimation: public Animation {

public:
    ChunLiWeakAirKickAnimation();
    ~ChunLiWeakAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKAIRKICKANIMATION_H
