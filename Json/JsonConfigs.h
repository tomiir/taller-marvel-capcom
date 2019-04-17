#ifndef JSON_2_JSONCONFIGS_H
#define JSON_2_JSONCONFIGS_H
#include <jsoncpp/json/json.h>
#include "JsonParser.h"
#include "../utils/Logger/Logger.h"

class JsonConfigs {
    JsonParser json = JsonParser(std::string());

public:
    JsonConfigs();

    std::string getLog();

    std::list<Battlefield> getBattlefields();

    std::list<JsonCharacter> getCharacters();

    std::vector<int> getScreenSize();

    int getCharactersSpeed();

    int getFPS();

    std::string getTitle();

    CLogger* logger = CLogger::GetLogger();
private:
    JsonParser fallbackJson = JsonParser(std::string());

};


#endif //JSON_2_JSONCONFIGS_H
