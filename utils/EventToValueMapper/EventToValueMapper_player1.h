//
// Created by magali on 08/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER1_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER1_H
#include "EventToValueMapper.h"

class EventToValueMapper_player1: public EventToValueMapper {
public:
    DirectionVector* map(SDL_Event event) override;
    bool changeCharacter(SDL_Event event) override;

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_PLAYER1_H
