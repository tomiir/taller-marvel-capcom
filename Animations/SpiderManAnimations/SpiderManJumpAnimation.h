//
// Created by arielpm on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANJUMPANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANJUMPANIMATION_H

#include "../Animation.h"


class SpiderManJumpAnimation: public Animation {

public:
    SpiderManJumpAnimation();
    ~SpiderManJumpAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANJUMPANIMATION_H
