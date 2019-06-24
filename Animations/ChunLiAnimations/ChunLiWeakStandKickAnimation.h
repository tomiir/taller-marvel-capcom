//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDKICKANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakStandKickAnimation: public Animation {

public:
    ChunLiWeakStandKickAnimation();
    ~ChunLiWeakStandKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDKICKANIMATION_H
