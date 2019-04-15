//
// Created by fede on 07/04/19.
//

#ifndef JSON_2_BATTLEFIELD_H
#define JSON_2_BATTLEFIELD_H


#include <string>

class Battlefield {

    std::string ruta;
    int zindex;
    int height;
    int width;

public:
    Battlefield(std::string ruta,int zindex,  int width, int height);
    std::string getFilePath();
    int getzIndex();
    int getHeight();
    int getWidth();
};



#endif //JSON_2_BATTLEFIELD_H
