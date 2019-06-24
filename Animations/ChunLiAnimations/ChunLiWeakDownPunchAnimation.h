//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNPUNCHANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakDownPunchAnimation: public Animation {

public:
    ChunLiWeakDownPunchAnimation();
    ~ChunLiWeakDownPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKDOWNPUNCHANIMATION_H
