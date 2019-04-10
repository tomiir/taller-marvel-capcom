//
// Created by arielpm on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKANIMATION_H
#define TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKANIMATION_H


#include "Animation.h"

class CaptainAmericaWalkFowardAnimation : public Animation{

public:
    CaptainAmericaWalkFowardAnimation();
    ~CaptainAmericaWalkFowardAnimation() = default;
    void init() override;
};

#endif //TALLER_MARVEL_CAPCOM_CAPTAINAMERICAWALKFOWARDANIMATION_H
