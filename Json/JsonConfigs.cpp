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

    while(iter != jsonEnd && fIter != fJsonEnd) {
        Battlefield battlefield;
        if((*iter).getError()){
            battlefield = (*fIter);
            logger -> Log("Parametros del Background " + (*fIter).getFilePath() + " mal cargados", ERROR, "");
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
        if((*iter).getError() || (*iter).getName() != (*fIter).getName()){
            character = (*fIter);
            logger -> Log("Parametros del Character " + (*fIter).getFilePath() + " mal cargados", ERROR, "");

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
