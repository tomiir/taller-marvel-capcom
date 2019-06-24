//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDPUNCHANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiWeakStandPunchAnimation: public Animation {

public:
    ChunLiWeakStandPunchAnimation();
    ~ChunLiWeakStandPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIWEAKSTANDPUNCHANIMATION_H
