//
// Created by magali on 08/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_H
#define TALLER_MARVEL_CAPCOM_MAPPER_H
#include <SDL_events.h>

class Mapper {

public:
    Mapper();
   ~Mapper();

    virtual char *map( SDL_Event event);
};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_H
