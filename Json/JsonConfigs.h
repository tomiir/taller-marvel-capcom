#ifndef JSON_2_JSONCONFIGS_H
#define JSON_2_JSONCONFIGS_H
#include <jsoncpp/json/json.h>
#include "JsonParser.h"


class JsonConfigs {
    JsonParser json = JsonParser(std::string());

public:
    JsonConfigs(std::string ruta);

    std::string getLog();

    std::list<Battlefield> getBattlefields();

    std::list<Character> getCharacters();

    std::list<int> getScreenSize();
};


#endif //JSON_2_JSONCONFIGS_H
