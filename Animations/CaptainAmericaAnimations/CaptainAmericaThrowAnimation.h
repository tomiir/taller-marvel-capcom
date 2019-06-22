//
// Created by arielpm on 21/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICATHROWANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICATHROWANIMATION_H


#include "../Animation.h"


class CaptainAmericaThrowAnimation: public Animation {

public:
    CaptainAmericaThrowAnimation();
    ~CaptainAmericaThrowAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICATHROWANIMATION_H
