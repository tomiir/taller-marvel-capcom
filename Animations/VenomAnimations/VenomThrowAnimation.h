//
// Created by arielpm on 21/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMTHROWANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMTHROWANIMATION_H

#include "../Animation.h"

class VenomThrowAnimation : public Animation{

public:
    VenomThrowAnimation();
    ~VenomThrowAnimation() = default;
    void init() override;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMTHROWANIMATION_H
