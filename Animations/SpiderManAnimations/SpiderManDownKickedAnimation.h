//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManDownKickedAnimation: public Animation {

public:
    SpiderManDownKickedAnimation();
    ~SpiderManDownKickedAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H
