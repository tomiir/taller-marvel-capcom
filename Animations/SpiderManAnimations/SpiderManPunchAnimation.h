//
// Created by fer on 01/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANPUNCHANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANPUNCHANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManPunchAnimation: public Animation {

public:
    SpiderManPunchAnimation();
    ~SpiderManPunchAnimation() = default;
    void init() override ;
};



#endif //TALLER_MARVEL_CAPCOM_SPIDERMANPUNCHANIMATION_H


