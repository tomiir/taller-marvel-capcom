//
// Created by magali on 08/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_H
#define TALLER_MARVEL_CAPCOM_MAPPER_H
#include <SDL_events.h>
#include <string.h>
#include <string>
#include <string.h>

using namespace std;

class Mapper {

public:
    Mapper();
   ~Mapper();

    virtual string map( SDL_Event event);
protected:
    string MAP_JUMP = "w";
    string MAP_LEFT = "a";
    string MAP_CROUCH = "s";
    string MAP_RIGHT = "d";
    string MAP_CHANGE = "c";
    string MAP_PUNCH = "p";

    string MAP_JUMP_LEFT = "q";
    string MAP_JUMP_RIGHT = "e";

//KEYUPS
    string MAP_GET_UP = "r";
    string MAP_STOP_LEFT = "t";
    string MAP_STOP_RIGHT = "y";
    string MAP_STOP_PUNCH = "u";
};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_H
