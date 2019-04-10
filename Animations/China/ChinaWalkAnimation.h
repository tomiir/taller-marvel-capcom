//
// Created by fer on 07/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_ChinaWALKANIMATION_H
#define TALLER_MARVEL_CAPCOM_ChinaWALKANIMATION_H


#include "../Animation.h"

class ChinaWalkAnimation : public Animation{

public:
    ChinaWalkAnimation();
    ~ChinaWalkAnimation() = default;
    void init() override;
};

#endif //TALLER_MARVEL_CAPCOM_ChinaWALKANIMATION_H
