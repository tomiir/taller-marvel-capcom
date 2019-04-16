//
// Created by arielpm on 09/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMJUMPANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMJUMPANIMATION_H

#include "../Animation.h"



class VenomJumpAnimation : public Animation{

public:
    VenomJumpAnimation();
    ~VenomJumpAnimation() = default;
    void init() override;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMJUMPANIMATION_H
