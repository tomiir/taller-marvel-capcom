//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CHUNLIPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_CHUNLIPUNCHANIMATION_H

#include "../Animation.h"
#include <SDL_timer.h>


class ChunLiPunchAnimation: public Animation {

public:
    ChunLiPunchAnimation();
    ~ChunLiPunchAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CHUNLIPUNCHANIMATION_H
