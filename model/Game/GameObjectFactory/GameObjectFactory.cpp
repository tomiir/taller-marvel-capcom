//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"
#include "../../../utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.h"
#include "../../../utils/SpriteManagers/SpiderManSpriteManager/SpiderManSpriteManager.h"
#include "../../../utils/SpriteManagers/ChunLiSpriteManager/ChunLiSpriteManager.h"
#include "../../../utils/Logger/Logger.h"
#include "../../../Json/JsonConfigs.h"
#include "../../../utils/SpriteManagers/NotFoundSpriteManager.h"
#include <map>

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;

}

GameObjectFactory::~GameObjectFactory() = default;

bool GameObjectFactory::existFile(const char* path){

    bool result = false;
    FILE* file;
    file = fopen(path, "rb");
    if(file){
        result = true;
        fclose(file);
    }
    return result;
}


vector<GameObject*> GameObjectFactory:: getGameObjectsCharacters_fight() {

    vector<GameObject*>  gameObjects;
    CLogger* logger = CLogger::GetLogger();

    logger -> Log("Creando personajes", INFO, "");

    map<string, SpriteManager*> spriteManagers;

    spriteManagers["CaptainAmerica"] = new CaptainAmericaSpriteManager();
    spriteManagers["SpiderMan"] = new SpiderManSpriteManager();
    spriteManagers["Venom"] = new VenomSpriteManager();
    spriteManagers["ChunLi"] = new ChunLiSpriteManager();
    spriteManagers["NotFound"] = new NotFoundSpriteManager();

    map<string, SpriteManager*>::iterator itrSprites = spriteManagers.begin();


    JsonConfigs* config = JsonConfigs::getJson();

    std::list<JsonCharacter> characters = config->getCharacters();


    list <JsonCharacter>::iterator iter = characters.begin();

    for (iter ;iter != characters.end();++iter) {

        std::string path = (*iter).getFilePath();

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int initialY = screenHeight - height;
        int zIndex = (*iter).getzIndex();
        string spriteManagerName = (*iter).getSpriteManager();
        string name = (*iter).getName();
        double size = (*iter).getSize();


        if(!existFile(path.c_str())){
            logger -> Log("No se encontró " + path + ", se utilizara la imagen NotFound", ERROR, "");
            path = "DefaultConfigs/NotFound.png";
            spriteManagerName = "NotFound";
        }

        if(!spriteManagers.count(spriteManagerName)){
            spriteManagerName = name;
            logger -> Log("No se encontró el sprite manager " + spriteManagerName + ", se utilizara el default", ERROR, "");
        }
        itrSprites = spriteManagers.find(spriteManagerName);
        SpriteManager* spriteManager = itrSprites->second;

        Character* C;
        if(gameObjects.size() < 2){

            C = new Character(path.c_str(), zIndex, renderer, spriteManager , width/2, initialY, name, size);
        }
        else{
            C = new Character(path.c_str(), zIndex, renderer, spriteManager ,(screenWidth - width) - (width/2), initialY, name, size) ;
        }

        gameObjects.push_back((C));
    }

    return gameObjects;

}

double GameObjectFactory::cameraSpeedPercentage(int widthMax, int widthImg) {
    double a = widthImg - screenWidth;
    double b = widthMax - screenWidth;
    return a/b;
}


vector<GameObject*> GameObjectFactory:: getGameObjectsBackgrounds_fight() {

    CLogger* logger = CLogger::GetLogger();

    vector<GameObject *> gameObjects;

    JsonConfigs* config = JsonConfigs::getJson();

    list <JsonBackground> battlefields = config->getJsonBackgrounds();

    int maxWidth = 0;
    int speedCharacter = config->getCharactersSpeed();

    list <JsonBackground>::iterator iter = battlefields.begin();
    for (iter ;iter != battlefields.end();++iter){

        std::string path = (*iter).getFilePath();

        if(!existFile(path.c_str())){
            logger -> Log("No se encontró " + path + ", se utilizara la imagen NotFound", ERROR, "");
            path = "DefaultConfigs/BackgroundNotFound.png";
        }

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int zIndex = (*iter).getzIndex();
        string name = (*iter).getName();

        Background *B = new Background(path.c_str(), zIndex, renderer, name, width, height, screenWidth, screenHeight);

        if (!B){
            //excepción
        }

        if (width > maxWidth) maxWidth = width;

        gameObjects.push_back(B);
    }

    vector <GameObject*>::iterator itr = gameObjects.begin();

    for (itr; itr != gameObjects.end(); ++itr){

        vector<int> info = (*itr)->getInfo();
        double speedPercentageB = cameraSpeedPercentage(maxWidth, info[0]);
        int cameraSpeedB = speedCharacter * speedPercentageB;
        dynamic_cast<Background*>(*itr)->setSpeeds(cameraSpeedB,speedPercentageB);
    }




    return gameObjects;

}