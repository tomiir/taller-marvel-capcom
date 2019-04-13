
#include <jsoncpp/json/json.h>
#include "Battlefield.h"
#include "Character.h"
#include <fstream>
#include <list>
#ifndef JSON_2_JSONPARSER_H
#define JSON_2_JSONPARSER_H

class JsonParser {
    Json::Value json;

    void setJson(std::string ruta);

public:
    JsonParser(std::string ruta);

    std::string getLog();

    std::list<Battlefield> getBattlefields();

    std::list<Character> getCharacter();

    std::list<int> getScreenSize();

};

#endif //JSON_2_JSONPARSER_H
