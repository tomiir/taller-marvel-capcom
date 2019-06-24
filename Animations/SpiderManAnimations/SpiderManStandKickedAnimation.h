//
// Created by arielpm on 14/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANSTANDKICKEDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANSTANDKICKEDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManStandKickedAnimation: public Animation {

public:
    SpiderManStandKickedAnimation();
    ~SpiderManStandKickedAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANSTANDKICKEDANIMATION_H
