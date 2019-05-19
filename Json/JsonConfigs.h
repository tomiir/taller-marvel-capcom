#ifndef JSON_2_JSONCONFIGS_H
#define JSON_2_JSONCONFIGS_H
#include <jsoncpp/json/json.h>
#include "JsonParser.h"
#include "../utils/Logger/Logger.h"
#include "JsonGameObject_charSelect.h"

class JsonConfigs {
    JsonParser json = JsonParser(std::string());

public:

    static JsonConfigs* getJson();

    std::list<JsonBackground> getJsonBackgrounds();

    std::list<JsonCharacter> getCharacters();

    std::vector<int> getScreenSize();

    std::list<JsonGameObject_charSelect> getGameObjectCharSelect();

    int getCharactersSpeed();

    int getFPS();

    std::string getTitle();

    CLogger* logger = CLogger::GetLogger();

    int getJumpSpeed();

private:
    JsonConfigs();
    JsonConfigs(const JsonConfigs&) = default;
    JsonParser fallbackJson = JsonParser(std::string());
    static JsonConfigs* this_json;

};


#endif //JSON_2_JSONCONFIGS_H
