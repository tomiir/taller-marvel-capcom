
#include <jsoncpp/json/json.h>
#include "Battlefield.h"
#include "JsonCharacter.h"
#include <fstream>
#include <list>
#include <vector>
#ifndef JSON_2_JSONPARSER_H
#define JSON_2_JSONPARSER_H

class JsonParser {
    Json::Value json;

    void setJson(std::string ruta);

public:
    JsonParser(std::string ruta);

    std::string getLog();

    std::list<Battlefield> getBattlefields();

    std::list<JsonCharacter> getCharacter();

    std::vector<int> getScreenSize();
    
    int getCharactersSpeed();

    int getFPS();

    std::string getTitle();

};

#endif //JSON_2_JSONPARSER_H
