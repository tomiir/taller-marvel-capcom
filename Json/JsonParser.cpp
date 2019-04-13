#include "JsonParser.h"
#include <fstream>
#include <iostream>

JsonParser::JsonParser(std::string ruta){
    this->setJson(ruta);
}


void JsonParser::setJson(std::string ruta) {

    std::ifstream in(ruta);
    Json::Value json;

    if(in.is_open()){
        std::cout << "Archivo abierto\n";
    }
    if (in.fail()) {
        std::cout << "no se abrio archivo\n";
    }
    try {
        in >> json;
    }
    catch (const Json::RuntimeError &error) {
        std::cout << error.what() << "Esto pasa siempre qque se abre por primera vez.\n";
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
                                ((*it)["background"]["zindex"]).asInt());

        battlefields.push_back(battlefield);
    }
    return battlefields;
    }

std::list<Character> JsonParser::getCharacter() {

    std::list<Character> characters;
    Json::Value json = this->json["characters"];

    for(Json::Value::iterator it=json.begin();it!=json.end();++it){
        Character character(((*it)["name"]).asString(),((*it)["filepath"]).asString(),((*it)["height"]).asInt(),
                ((*it)["whidth"]).asInt(),((*it)["zindex"]).asInt());

        characters.push_back(character);
    }
    return characters;

}

std::list<int> JsonParser::getScreenSize() {

    std::list<int> screen;
    Json::Value json = this->json["window"];

    screen.push_back((json["width"]).asInt());
    screen.push_front((json["height"]).asInt());

    return screen;
}





