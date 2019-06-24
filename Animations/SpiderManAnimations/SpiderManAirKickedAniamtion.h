//
// Created by arielpm on 14/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANAIRKICKEDANIAMTION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANAIRKICKEDANIAMTION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManAirKickedAnimation: public Animation {

public:
    SpiderManAirKickedAnimation();
    ~SpiderManAirKickedAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANAIRKICKEDANIAMTION_H
