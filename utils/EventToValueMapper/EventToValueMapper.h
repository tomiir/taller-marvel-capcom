//
// Created by magali on 01/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
#define TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H

#include <vector>
#include <SDL_events.h>

class EventToValueMapper {

private:
    std::vector<int> dir; //

public:
    EventToValueMapper();
    ~EventToValueMapper();
    std::vector<int> map(SDL_Event event);

};


#endif //TALLER_MARVEL_CAPCOM_EVENTTOVALUEMAPPER_H
