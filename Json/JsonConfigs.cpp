#include "JsonConfigs.h"
#include <string.h>

bool existFile(const char* path){

    bool result = false;
    FILE* file;
    file = fopen(path, "rb");
    if(file){
        result = true;
        fclose(file);
    }
    return result;
}

JsonConfigs::JsonConfigs() {
    string defaultJson = "defaultConfigs.json";
    string baseRoute = "configs.json";
    if(!existFile(baseRoute.c_str())) {
        baseRoute =  defaultJson;
        logger -> Log("Falló la carga del Json, utilizando el fallback", ERROR, "File " + baseRoute +" does not exist");
    }
    this->fallbackJson  = JsonParser(defaultJson);
    this->json = JsonParser(baseRoute);
}

std::string JsonConfigs::getLog() {
    return json.getLog();
}

std::list<Battlefield> JsonConfigs::getBattlefields() {
    std::list<Battlefield> retVal;
    std::list<Battlefield> fJsonBFs = fallbackJson.getBattlefields();
    std::list<Battlefield> jsonBFs = json.getBattlefields();
    std::list<Battlefield>::iterator iter = jsonBFs.begin();
    std::list<Battlefield>::iterator fIter = fJsonBFs.begin();
    auto fJsonEnd = fJsonBFs.end();
    auto jsonEnd = jsonBFs.end();

    for(;iter != jsonEnd && fIter != fJsonEnd; ) {
        Battlefield battlefield = (*iter).getError() ? (*fIter) : (*iter);
        retVal.push_back(battlefield);
        ++iter;
        ++fIter;
    }
    iter=jsonBFs.begin();
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
