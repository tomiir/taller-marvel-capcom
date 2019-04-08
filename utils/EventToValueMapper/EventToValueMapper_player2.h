//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER2_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER2_H

#include "EventToValueMapper.h"

class EventToValueMapper_player2: public EventToValueMapper {

public:
    DirectionVector* map(SDL_Event event);

};

#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER2_H
