//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_1_H
#define TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_1_H

#include "Mapper_fight.h"

class Mapper_fight_1: public Mapper_fight {

public:
    string map(SDL_Event event) override;

};

#endif //TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_1_H
