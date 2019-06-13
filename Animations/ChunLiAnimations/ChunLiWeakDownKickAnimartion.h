//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNKICKANIMARTION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNKICKANIMARTION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakDownKickAnimation: public Animation {

public:
    ChunLiWeakDownKickAnimation();
    ~ChunLiWeakDownKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNKICKANIMARTION_H
