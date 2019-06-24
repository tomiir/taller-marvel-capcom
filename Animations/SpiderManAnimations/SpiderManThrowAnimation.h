//
// Created by arielpm on 21/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANTHROWANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANTHROWANIMATION_H


#include "../Animation.h"


class SpiderManThrowAnimation: public Animation {

public:
    SpiderManThrowAnimation();
    ~SpiderManThrowAnimation() = default;
    void init() override ;
};

#endif //TALLER_MARVEL_CAPCOM_SPIDERMANTHROWANIMATION_H
