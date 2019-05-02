//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_2_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_2_H

#include "EventToValueMapper_charSelect.h"

class EventToValueMapper_charSelect_2: public EventToValueMapper_charSelect {

public:
    EventToValueMapper_charSelect_2();
    ~EventToValueMapper_charSelect_2();
    string map( SDL_Event event) override;

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_2_H
