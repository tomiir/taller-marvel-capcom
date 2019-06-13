//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H


#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManKickedAnimation: public Animation {

public:
    SpiderManKickedAnimation();
    ~SpiderManKickedAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANKICKEDANIMATION_H
