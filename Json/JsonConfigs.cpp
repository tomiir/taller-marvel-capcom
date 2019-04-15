#include "JsonConfigs.h"

JsonConfigs::JsonConfigs(std::string ruta){
    JsonParser json(ruta);
    this->json  = json;
}

std::string JsonConfigs::getLog() {
    return json.getLog();
}

std::list<Battlefield> JsonConfigs::getBattlefields(){
    return json.getBattlefields();
}

std::list<JsonCharacter> JsonConfigs::getCharacters() {
    return json.getCharacter();
}

std::vector<int> JsonConfigs::getScreenSize() {
    return json.getScreenSize();
}

int JsonConfigs::getCharactersSpeed(){
    return json.getCharactersSpeed();
}
