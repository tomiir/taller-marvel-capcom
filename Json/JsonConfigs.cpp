#include "JsonConfigs.h"
#include <string.h>


JsonConfigs::JsonConfigs() {
    std::string defaultJson = "./defaultConfigs";
    this -> fallbackJson = JsonParser(defaultJson);
    try {
        JsonParser json = JsonParser("configs.json");
        this->json  = json;
    } catch(std::exception* e) {
        logger->Log("Falló la apertura del JSON", ERROR, e->what());
        this->json  = fallbackJson;
    }

}

std::string JsonConfigs::getLog() {
    return json.getLog();
}

std::list<Battlefield> JsonConfigs::getBattlefields() {
    std::list<Battlefield> retVal;
    try {
        retVal = json.getBattlefields();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener los campos de batalla, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getBattlefields();
    }
    return retVal;
}

std::list<JsonCharacter> JsonConfigs::getCharacters() {
    std::list<JsonCharacter> retVal;
    try {
        retVal = json.getCharacter();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener los campos de personajes, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getCharacter();
    }
    return retVal;
}

std::vector<int> JsonConfigs::getScreenSize() {
    std::vector<int> retVal;
    try {
        retVal = json.getScreenSize();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener el tamaño de la pantalla, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getScreenSize();
    }
    return retVal;
}

int JsonConfigs::getCharactersSpeed(){
    int retVal;
    try {
        retVal = json.getCharactersSpeed();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener las velocidades de los personajes, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getCharactersSpeed();
    }
    return retVal;
}

int JsonConfigs::getFPS(){
   int retVal;
    try {
        retVal = json.getFPS();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener los FPS, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getFPS();
    }
    return retVal;
}

std::string JsonConfigs::getTitle(){
    std::string retVal;
    try {
        retVal = json.getTitle();
    } catch (std::exception e) {
        logger  ->Log("Error al querer obtener el titulo de la pantalla, utilizando el fallback", ERROR, e.what());
        retVal = fallbackJson.getTitle();
    }
    return retVal;
}
