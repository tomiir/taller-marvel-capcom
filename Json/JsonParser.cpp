#include "JsonParser.h"
#include <fstream>
#include <iostream>
#include "../utils/Logger/Logger.h"

JsonParser::JsonParser(std::string ruta){
    this->setJson(ruta);
}


void JsonParser::setJson(std::string ruta){

    if(ruta.empty()) return;
    CLogger* logger = CLogger::GetLogger();

    std::ifstream in(ruta);
    Json::Value json;



    if(in.is_open()){
        logger -> Log("Archivo abierto\n", INFO,"");
    }
    if (in.fail()) {

        logger -> Log("Falló la apertura de archivo\n", INFO,"");
        in.clear();
    }
    try {
        in >> json;
    } catch (const Json::RuntimeError &error) {
            logger -> Log("Esto pasa siempre que se abre por primera vez.\n", ERROR,error.what());
            in.clear();
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
        if(
                ((*it)["background"]["filepath"]).asString() == "null" ||
                !((*it)["background"]["zindex"]).asInt() || ((*it)["background"]["zindex"]).asInt() <= 0 ||
                !((*it)["background"]["width"]).asInt() || ((*it)["background"]["width"]).asInt() <= 0 ||
                !((*it)["background"]["height"]).asInt() || ((*it)["background"]["height"]).asInt() <= 0 )
        {

            battlefields.push_back(Battlefield());
        }
        else {
            Battlefield battlefield(
                    ((*it)["background"]["filepath"]).asString(),
                    ((*it)["background"]["zindex"]).asInt(),
                    ((*it)["background"]["width"]).asInt(),
                    ((*it)["background"]["height"]).asInt()
                    );

            battlefields.push_back(battlefield);
        }
    }
    return battlefields;
    }

std::list<JsonCharacter> JsonParser::getCharacter() {

    std::list<JsonCharacter> characters;
    Json::Value json = this->json["characters"];


    for(Json::Value::iterator it=json.begin();it!=json.end();++it){

        if(
            ((*it)["name"]).asString() == "null" ||
            ((*it)["filepath"]).asString() == "null" ||
            !((*it)["height"]).asInt()  || ((*it)["height"]).asInt() <= 0||
            !((*it)["width"]).asInt()  || ((*it)["width"]).asInt() <= 0 ||
            !((*it)["zindex"]).asInt() || ((*it)["zindex"]).asInt() <= 0 ||
            ((*it)["spriteManagerName"]).asString() == "null" ||
            !((*it)["size"]).asDouble() )
        {
                    characters.push_back(JsonCharacter());
        }

        else
            {
                JsonCharacter character(
                        ((*it)["name"]).asString(),
                        ((*it)["filepath"]).asString(),
                        ((*it)["height"]).asInt(),
                        ((*it)["width"]).asInt(),
                        ((*it)["zindex"]).asInt(),
                        ((*it)["crowchedDownY"]).asInt(),
                        ((*it)["spriteManagerName"]).asString(),
                        ((*it)["size"]).asDouble()
                        );



        characters.push_back(character);
        }
    }
    return characters;

}

std::vector<int> JsonParser::getScreenSize() {

    std::vector<int> screen;
    Json::Value json = this->json["window"];

    if( !(json["width"]).asInt() || !(json["height"]).asInt() || (json["width"]).asInt() <= 0 || (json["height"]).asInt() <= 0) screen = {-1,-1};
    else screen = {(json["width"]).asInt(), (json["height"]).asInt()};

    return screen;
}

int JsonParser::getCharactersSpeed(){

    Json::Value json = this->json["gameParameters"];

    if( !(json["charactersSpeed"]).asInt() || (json["charactersSpeed"]).asInt() <= 0) return -1;
    return (json["charactersSpeed"]).asInt();
}

int JsonParser::getFPS(){

    Json::Value json = this->json["Graphics"];

    if( !(json["FPS"]).asInt() || (json["FPS"]).asInt() <= 0) return -1;
    return (json["FPS"]).asInt();

}

std::string JsonParser::getTitle() {

    Json::Value json = this->json["Title"];

    if( (json["title"]).asString() == "null" ) return "null";
    return (json["title"]).asString();

}

int JsonParser::getJumpSpeed() {

    Json::Value json = this->json["gameParameters"];

    if( !(json["jumpSpeed"]).asInt() || (json["jumpSpeed"]).asInt() <= 0) return -1;
    return (json["jumpSpeed"]).asInt();

}





