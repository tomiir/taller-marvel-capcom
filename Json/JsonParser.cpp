#include "JsonParser.h"
#include <fstream>
#include <iostream>
#include "../utils/Logger/Logger.h"

JsonParser::JsonParser(std::string ruta){
    this->setJson(ruta);
}


void JsonParser::setJson(std::string ruta) {

    CLogger* logger = CLogger::GetLogger();

    std::ifstream in(ruta);
    Json::Value json;

    if(in.is_open()){
        logger -> Log("Archivo abierto\n", INFO,"");
    }
    if (in.fail()) {
        logger -> Log("Falló la apertura de archivo\n", INFO,"");
    }
    try {
        in >> json;
    }
    catch (const Json::RuntimeError &error) {
        logger -> Log("Esto pasa siempre qque se abre por primera vez.\n", ERROR,error.what());
    }
    this->json = json;
}

std::string JsonParser::getLog() {
    return json["debug"].asString();
}

std::list<Battlefield> JsonParser::getBattlefields() {

    std::list<Battlefield> battlefields;
    Json::Value json = this->json["battlefield"];

    for(Json::Value::iterator it=json.begin(); it!=json.end(); ++it) {
        Battlefield battlefield(((*it)["background"]["filepath"]).asString(),
                                ((*it)["background"]["zindex"]).asInt(),
                                ((*it)["background"]["width"]).asInt(),
                                ((*it)["background"]["height"]).asInt() );

        battlefields.push_back(battlefield);
    }
    return battlefields;
    }

std::list<JsonCharacter> JsonParser::getCharacter() {

    std::list<JsonCharacter> characters;
    Json::Value json = this->json["characters"];

    for(Json::Value::iterator it=json.begin();it!=json.end();++it){
        JsonCharacter character(((*it)["name"]).asString(),
                            ((*it)["filepath"]).asString(),
                            ((*it)["height"]).asInt(),
                            ((*it)["width"]).asInt(),
                            ((*it)["zindex"]).asInt(),
                            ((*it)["crowchedDownY"]).asInt(),
                            ((*it)["spriteManagerName"]).asString());

        characters.push_back(character);
    }
    return characters;

}

std::vector<int> JsonParser::getScreenSize() {

    std::vector<int> screen;
    Json::Value json = this->json["window"];

    screen[0] = (json["width"]).asInt();
    screen[1] = (json["height"]).asInt();

    return screen;
}

int JsonParser::getCharactersSpeed(){

    Json::Value json = this->json["gameParameters"];

    return (json["charactersSpeed"]).asInt();
}





