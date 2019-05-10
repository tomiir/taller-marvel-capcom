//
// Created by magali on 01/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_H
#define TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_H

#include <vector>
#include <SDL_events.h>
#include "../../Vector2D/DirectionVector.h"
#include "../Mapper.h"



class Mapper_fight: public Mapper{


public:
    Mapper_fight();
    ~Mapper_fight();
    virtual char* map(SDL_Event event);
    bool changeCharacter(SDL_Event event);

protected:
    bool changeCharacter_;

};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_FIGHT_H
