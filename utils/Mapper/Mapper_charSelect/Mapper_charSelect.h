//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H

#include <vector>
#include <SDL_events.h>
#include <iostream>
#include <map>
#include <string.h>
#include "../Mapper.h"

using namespace std;

class Mapper_charSelect: public Mapper{

public:
    Mapper_charSelect();
    virtual ~Mapper_charSelect();
    virtual char* map(SDL_Event event);

protected:


};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H
