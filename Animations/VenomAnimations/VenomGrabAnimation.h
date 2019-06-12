//
// Created by arielpm on 12/06/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VENOMGRABANIMATION_H
#define TALLER_MARVEL_CAPCOM_VENOMGRABANIMATION_H

#include "../Animation.h"

class VenomGrabAnimation : public Animation{

public:
    VenomGrabAnimation();
    ~VenomGrabAnimation() = default;
    void init() override;

};


#endif //TALLER_MARVEL_CAPCOM_VENOMGRABANIMATION_H
