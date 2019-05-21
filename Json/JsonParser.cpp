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
        logger -> Log("Archivo abierto: " + ruta + "\n", INFO,"");
    }
    if (in.fail()) {
        logger->Log("Falló la apertura de archivo: " + ruta + "\n", INFO, "");
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

std::string JsonParser::getLog() {   //DESPUES USARLO, DE MOMENTO ESTA HARCODEADO
    return json["debug"].asString();
}

std::list<JsonBackground> JsonParser::getJsonBackgrounds() {

    std::list<JsonBackground> backgrounds;
    Json::Value json = this->json["battlefield"];


    for(Json::Value::iterator it=json.begin(); it!=json.end(); ++it) {

        std::list<std::string> errors;
        bool error = false;


        if( !((*it)["background"]["name"]).isString() || ((*it)["background"]["name"]).asString() == "null"){
            error = true;
            errors.push_back("name");
        }
        if( !((*it)["background"]["filepath"]).isString() || ((*it)["background"]["filepath"]).asString() == "null"){
            error = true;
            errors.push_back("filepath");
        }
        if( !((*it)["background"]["zindex"]).isInt() || ((*it)["background"]["zindex"]).asInt() <= 0 ){
            error = true;
            errors.push_back("zindex");
        }
        if( !((*it)["background"]["width"]).isInt() || ((*it)["background"]["width"]).asInt() <= 0 ){
            error = true;
            errors.push_back("width");
        }
        if( !((*it)["background"]["height"]).isInt() || ((*it)["background"]["height"]).asInt() <= 0 ){
            error = true;
            errors.push_back("height");
        }
        if(error){
            backgrounds.push_back(JsonBackground(errors));
        }

        else {
            JsonBackground battlefield(
                    ((*it)["background"]["name"]).asString(),
                    ((*it)["background"]["filepath"]).asString(),
                    ((*it)["background"]["zindex"]).asInt(),
                    ((*it)["background"]["width"]).asInt(),
                    ((*it)["background"]["height"]).asInt()
                    );

            backgrounds.push_back(battlefield);
        }
    }

    return backgrounds;
}

std::list<JsonCharacter> JsonParser::getCharacter() {

    std::list<JsonCharacter> characters;
    Json::Value json = this->json["characters"];


    for(Json::Value::iterator it=json.begin();it!=json.end();++it){
        std::list<std::string> errors;
        bool error = false;

        if( !((*it)["name"]).isString() || ((*it)["name"]).asString() == "null"){
            error = true;
            errors.push_back("name");
        }
        if( !((*it)["filepath"]).isString() || ((*it)["filepath"]).asString() == "null"){
            error = true;
            errors.push_back("filepath");
        }
        if( !((*it)["height"]).isInt()  || ((*it)["height"]).asInt() <= 0){
            error = true;
            errors.push_back("height");
        }
        if( !((*it)["width"]).isInt()  || ((*it)["width"]).asInt() <= 0){
            error = true;
            errors.push_back("width");
        }
        if( !((*it)["zindex"]).isInt() || ((*it)["zindex"]).asInt() <= 0){
            error = true;
            errors.push_back("zindex");
        }
        if( !((*it)["spriteManagerName"]).isString() || ((*it)["spriteManagerName"]).asString() == "null"){
            error = true;
            errors.push_back("spriteManagerName");
        }
        if( !((*it)["size"]).isDouble()){
            error = true;
            errors.push_back("size");
        }
        if(error) characters.push_back(JsonCharacter(errors));

        else
            {
                JsonCharacter character(
                        ((*it)["name"]).asString(),
                        ((*it)["filepath"]).asString(),
                        ((*it)["height"]).asInt(),
                        ((*it)["width"]).asInt(),
                        ((*it)["zindex"]).asInt(),
                        ((*it)["spriteManagerName"]).asString(),
                        ((*it)["size"]).asDouble()
                        );



        characters.push_back(character);
        }
    }
    return characters;

}

std::list<JsonGameObject_charSelect> JsonParser:: getJsonGameobject_charSelect(){

    std::list<JsonGameObject_charSelect> gameObjects;
    Json::Value json_ = this->json["caca"];


    Json::Value::iterator it=json_.begin();

    for(;it!=json_.end();++it){
        std::list<std::string> errors;
        bool error = false;

        if( !((*it)["name"]).isString() || ((*it)["name"]).asString() == "null"){
            error = true;
            errors.push_back("name");
        }
        if( !((*it)["filepath"]).isString() || ((*it)["filepath"]).asString() == "null"){
            error = true;
            errors.push_back("filepath");
        }
        if( !((*it)["x"]).isInt()  || ((*it)["x"]).asInt() < 0){
            error = true;
            errors.push_back("x");
        }
        if( !((*it)["y"]).isInt()  || ((*it)["y"]).asInt() < 0){
            error = true;
            errors.push_back("y");
        }
        if( !((*it)["height"]).isInt() || ((*it)["height"]).asInt() < 0){
            error = true;
            errors.push_back("height");
        }
        if( !((*it)["width"]).isInt() || ((*it)["width"]).asInt() < 0){
            error = true;
            errors.push_back("width");
        }
        if(error) gameObjects.push_back(JsonGameObject_charSelect(errors));

        else
        {

            //std::vector<int> posc = {((*it)["x"]).asInt(),
            //                         ((*it)["y"]).asInt(),
            //                         ((*it)["height"]).asInt(),
            //                         ((*it)["width"]).asInt()};
            std::string name = ((*it)["name"]).asString();
            std::string path = ((*it)["filepath"]).asString();

            std::vector<int> posc;
            int x = ((*it)["x"]).asInt();
            posc.push_back(x);
            int y = ((*it)["y"]).asInt();
            posc.push_back(y);
            int height = ((*it)["height"]).asInt();
            posc.push_back(height);
            int width = ((*it)["width"]).asInt();
            posc.push_back(width);



            JsonGameObject_charSelect gameObject(path,posc,name);

            gameObjects.push_back(gameObject);
        }
    }

    return gameObjects;


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

int JsonParser::getNumberOfClients() {
    Json::Value json = this->json["server"];

    if( !(json["clients"]).asInt() || (json["clients"]).asInt() < 2  || (json["clients"]).asInt() > 4) return -1;
    return (json["clients"]).asInt();
}

int JsonParser::getNumberOfPort() {
    Json::Value json = this->json["server"];

    if( !(json["port"]).asInt() || (json["port"]).asInt() < 0) return -1;
    return (json["port"]).asInt();
}





