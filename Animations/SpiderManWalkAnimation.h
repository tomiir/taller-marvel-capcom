//
// Created by arielpm on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_SPIDERMANWALKANIMATION_H
#define TALLER_MARVEL_CAPCOM_SPIDERMANWALKANIMATION_H

#include "Animation.h"


class SpiderManWalkAnimation: public Animation {

public:
    SpiderManWalkAnimation();
    ~SpiderManWalkAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_SPIDERMANWALKANIMATION_H
