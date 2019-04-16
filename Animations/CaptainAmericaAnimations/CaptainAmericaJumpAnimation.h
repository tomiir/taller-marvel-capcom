//
// Created by arielpm on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAJUMPANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAJUMPANIMATION_H

#include "../Animation.h"


class CaptainAmericaJumpAnimation: public Animation {

public:
    CaptainAmericaJumpAnimation();
    ~CaptainAmericaJumpAnimation() = default;
    void init() override ;
};


#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAJUMPANIMATION_H
