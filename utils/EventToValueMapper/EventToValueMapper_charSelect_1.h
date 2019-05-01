//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H

#include "EventToValueMapper_charSelect.h"
#include <map>

class EventToValueMapper_charSelect_1: EventToValueMapper_charSelect {

    EventToValueMapper_charSelect_1();
    ~EventToValueMapper_charSelect_1();
    void map(ViewController_charSelect* viewController, SDL_Event event) override;

private:
    //

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_CHARSELECT_1_H
