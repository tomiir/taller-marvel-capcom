//
// Created by arielpm on 13/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGAIRKICKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGAIRKICKANIMATION_H

#include <SDL_timer.h>
#include "../Animation.h"


class SpiderManStrongAirKickAnimation: public Animation {

public:
    SpiderManStrongAirKickAnimation();
    ~SpiderManStrongAirKickAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANSTRONGAIRKICKANIMATION_H
