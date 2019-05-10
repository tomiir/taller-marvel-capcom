//
// Created by magali on 01/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H
#define TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H

#include <vector>
#include <SDL_events.h>
#include <iostream>
#include <map>
#include <string.h>
#include "../Mapper.h"

using namespace std;

class Mapper_charSelect: public Mapper{

public:
    Mapper_charSelect();
    virtual ~Mapper_charSelect();
    virtual char* map(SDL_Event event);
    string getPreselected();

protected:
    string preselected;

    std::map<string, string> map_preselected;
    std::map<string, std::map<string,string> > map_map;
    std::map<string, string> cap_america;
    std::map<string, string> chun_li;
    std::map<string, string> spider_man;
    std::map<string, string> venom;


};


#endif //TALLER_MARVEL_CAPCOM_MAPPER_CHARSELECT_H
