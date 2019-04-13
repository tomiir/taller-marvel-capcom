//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_BATTLEFIELD_H
#define JSON_2_BATTLEFIELD_H


#include <string>

class Battlefield {
    std::string ruta;
    int zindex;

public:
    Battlefield(std::string ruta,int zindex);
    std::string getRuta();
    int getzIndex();
};



#endif //JSON_2_BATTLEFIELD_H
