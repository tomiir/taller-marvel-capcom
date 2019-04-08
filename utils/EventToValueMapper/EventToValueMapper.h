//
// Created by magali on 01/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H

#include <vector>
#include <SDL_events.h>
#include "../Vector2D/DirectionVector.h"



class EventToValueMapper {


public:
    EventToValueMapper();
    ~EventToValueMapper();
    virtual DirectionVector* map(SDL_Event event);
    virtual bool changeCharacter(SDL_Event event);

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
