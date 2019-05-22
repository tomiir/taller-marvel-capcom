#include "JsonConfigs.h"
#include <string.h>
#include "JsonSintax.h"

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

    bool error = false;
    const char *defaultJson = "../DefaultConfigs/defaultConfigs.json";
    const char *baseRoute = "../configs.json";
    if(!existFile(baseRoute)) {
        baseRoute =  defaultJson;
        logger -> Log("Falló la carga del Json, utilizando el fallback", ERROR, "File doesnt exist" );
    }

    char my_character;
    FILE *jsonptr;
    jsonptr = fopen(baseRoute, "r");
    JSON_checker jc = new_JSON_checker(5000);
    while ( (my_character = getc(jsonptr) )!= EOF){

        if (my_character <= 0) {
            break;
        }
        if (!JSON_checker_char(jc, my_character)) {
            logger -> Log("Error de formato en configs.json ,utilizando el fallback", ERROR, "");
            this->json = JsonParser(defaultJson);
            error = true;
        }
    }
    if (!JSON_checker_done(jc)) {
        logger -> Log("Error de formato en configs.json ,utilizando el fallback", ERROR, "");
        this->json = JsonParser(defaultJson);
        error = true;
    }


    this->fallbackJson  = JsonParser(defaultJson);
    if( !error ){
        this->json = JsonParser(baseRoute);
    }
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

std::list<JsonGameObject_charSelect> JsonConfigs::getGameObjectCharSelect() {
    std::list<JsonGameObject_charSelect> retVal;
    std::list<JsonGameObject_charSelect> fJsonGO = fallbackJson.getJsonGameobject_charSelect();
    std::list<JsonGameObject_charSelect> jsonGO = json.getJsonGameobject_charSelect();
    std::list<JsonGameObject_charSelect>::iterator iter = jsonGO.begin();
    std::list<JsonGameObject_charSelect>::iterator fIter = fJsonGO.begin();

    auto fJsonEnd = fJsonGO.end();
    auto jsonEnd = jsonGO.end();

    while(iter != jsonEnd && fIter != fJsonEnd) {

        JsonGameObject_charSelect GO;
        if((*iter).getError() || (*iter).getName() != (*fIter).getName() || (*iter).getFilePath() != (*fIter).getFilePath()){


            std::list<std::string> errorsList = (*iter).getErrorList();
            std::list<std::string>::iterator errorIter = errorsList.begin();

            if( (*iter).getFilePath() != (*fIter).getFilePath() ) logger->LogError("filepath", (*fIter).getName());

            for(; errorIter != errorsList.end(); ++errorIter){
                logger->LogError( (*errorIter), (*fIter).getName());
            }
            GO = (*fIter);
        }
        else GO = (*iter);

        retVal.push_back(GO);
        ++iter;
        ++fIter;
    }

    return retVal;
}

int JsonConfigs::getNumberOfClients() {

    int retVal = json.getNumberOfClients();

    if (retVal == -1) {
        logger->Log("Error al querer obtener la cantidad de clients, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getNumberOfClients();
    }
    return retVal;
}

int JsonConfigs::getNumberOfPort() {

    int retVal = json.getNumberOfPort();

    if (retVal == -1) {
        logger->Log("Error al querer obtener el número de puerto, utilizando el fallback", ERROR, "");
        retVal = fallbackJson.getNumberOfPort();
    }
    return retVal;
}
