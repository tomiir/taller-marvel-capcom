//
// Created by magali on 01/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H

#include <vector>
#include <SDL_events.h>

class EventToValueMapper {


public:
    EventToValueMapper();
    ~EventToValueMapper();
    std::vector<int> map(SDL_Event event,  std::vector<int> dir );

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
