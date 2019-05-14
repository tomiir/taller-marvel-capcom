//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_1_H
#define TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_1_H

#include "Mapper_charSelect.h"
#include <map>

class Mapper_charSelect_1: public Mapper_charSelect {

public:
    Mapper_charSelect_1();

    string map( SDL_Event event) override;

};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_1_H
