//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMKICKEDANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMKICKEDANIMATION_H


#include "../Animation.h"

class VenomDownKickedAnimation : public Animation{

public:
    VenomDownKickedAnimation();
    ~VenomDownKickedAnimation() = default;
    void init() override;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMKICKEDANIMATION_H
