//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H

#include "EventToValueMapper_charSelect.h"
#include <map>

class EventToValueMapper_charSelect_1: public EventToValueMapper_charSelect {

public:
    EventToValueMapper_charSelect_1();

    string map( SDL_Event event) override;

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H
