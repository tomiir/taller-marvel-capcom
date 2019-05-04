#include "JsonConfigs.h"
#include <string.h>

JsonConfigs* JsonConfigs::this_json = NULL;

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

    string defaultJson = "DefaultConfigs/defaultConfigs.json";
    string baseRoute = "configs.json";
    if(!existFile(baseRoute.c_str())) {
        baseRoute =  defaultJson;
        logger -> Log("Falló la carga del Json, utilizando el fallback", ERROR, "File " + baseRoute +" does not exist");
    }
    this->fallbackJson  = JsonParser(defaultJson);
    this->json = JsonParser(baseRoute);
}


std::list<JsonBackground> JsonConfigs::getJsonBackgrounds() {

    std::list<JsonBackground> retVal;
    std::list<JsonBackground> fJsonBFs = fallbackJson.getJsonBackgrounds();
    std::list<JsonBackground> jsonBFs = json.getJsonBackgrounds();
    std::list<JsonBackground>::iterator iter = jsonBFs.begin();
    std::list<JsonBackground>::iterator fIter = fJsonBFs.begin();
    auto fJsonEnd = fJsonBFs.end();
    auto jsonEnd = jsonBFs.end();

    while(iter != jsonEnd && fIter != fJsonEnd) {
        JsonBackground battlefield;
        if((*iter).getError() || (*iter).getName() != (*fIter).getName() || (*iter).getFilePath() != (*fIter).getFilePath()){

            std::list<std::string> errorsList = (*iter).getErrorList();
            std::list<std::string>::iterator errorIter = errorsList.begin();

            if( (*iter).getFilePath() != (*fIter).getFilePath() ) logger->LogError("filepath", (*fIter).getName());

            for(; errorIter != errorsList.end(); ++errorIter){
                logger->LogError( (*errorIter), (*fIter).getName());
            }

            battlefield = (*fIter);
        }
        else battlefield = (*iter);
        retVal.push_back(battlefield);
        ++iter;
        ++fIter;
    }
    iter=jsonBFs.begin();
    return retVal;
}

std::list<JsonCharacter> JsonConfigs::getCharacters() {

    std::list<JsonCharacter> retVal;
    std::list<JsonCharacter> fJsonChars = fallbackJson.getCharacter();
    std::list<JsonCharacter> jsonChars = json.getCharacter();
    std::list<JsonCharacter>::iterator iter = jsonChars.begin();
    std::list<JsonCharacter>::iterator fIter = fJsonChars.begin();

    auto fJsonEnd = fJsonChars.end();
    auto jsonEnd = jsonChars.end();

    while(iter != jsonEnd && fIter != fJsonEnd) {

        JsonCharacter character;
        if((*iter).getError() || (*iter).getName() != (*fIter).getName() || (*iter).getFilePath() != (*fIter).getFilePath()){


            std::list<std::string> errorsList = (*iter).getErrorList();
            std::list<std::string>::iterator errorIter = errorsList.begin();

            if( (*iter).getFilePath() != (*fIter).getFilePath() ) logger->LogError("filepath", (*fIter).getName());

            for(; errorIter != errorsList.end(); ++errorIter){
                logger->LogError( (*errorIter), (*fIter).getName());
            }
            character = (*fIter);
        }
        else character = (*iter);

        retVal.push_back(character);
        ++iter;
        ++fIter;
    }
    iter=jsonChars.begin();
    return retVal;
}

std::vector<int> JsonConfigs::getScreenSize() {

    std::vector<int> retVal = json.getScreenSize();

    if( retVal[0] == -1 ){
        logger  ->Log("Error al querer obtener el tamaño de la pantalla, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getScreenSize();
    }

    return retVal;
}

int JsonConfigs::getCharactersSpeed(){

    int retVal = json.getCharactersSpeed();

    if(retVal == -1){
        logger  ->Log("Error al querer obtener las velocidades de los personajes, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getCharactersSpeed();
    }
    return retVal;
}

int JsonConfigs::getFPS(){
   int retVal = json.getFPS();

   if(retVal == -1){
       logger  ->Log("Error al querer obtener los FPS, utilizando el fallback", ERROR, "");
       retVal = fallbackJson.getFPS();
   }

   return retVal;
}

std::string JsonConfigs::getTitle(){

    std::string retVal = json.getTitle();
    if(retVal == "null"){
        logger  ->Log("Error al querer obtener el titulo de la pantalla, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getTitle();
    }
    return retVal;
}

int JsonConfigs::getJumpSpeed() {

    int retVal = json.getJumpSpeed();

    if (retVal == -1) {
        logger->Log("Error al querer obtener la velocidad de salto, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getJumpSpeed();
    }
    return retVal;
}

JsonConfigs* JsonConfigs::getJson() {
    if (this_json == NULL) {
        this_json = new JsonConfigs();
    }
    return this_json;
}