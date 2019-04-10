//
// Created by fer on 07/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKANIMATION_H


#include "../Animation.h"

class CaptainAmericaWalkAnimation : public Animation{

public:
    CaptainAmericaWalkAnimation();
    ~CaptainAmericaWalkAnimation() = default;
    void init() override;
};

#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKANIMATION_H
