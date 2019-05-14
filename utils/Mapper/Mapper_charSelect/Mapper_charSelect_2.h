//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_2_H
#define TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_2_H

#include "Mapper_charSelect.h"

class Mapper_charSelect_2: public Mapper_charSelect {

public:
    Mapper_charSelect_2();

    string map( SDL_Event event) override;

};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_2_H
