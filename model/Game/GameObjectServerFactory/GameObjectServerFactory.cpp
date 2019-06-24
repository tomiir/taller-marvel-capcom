//
// Created by arielpm on 17/05/19.
//

#include "GameObjectServerFactory.h"
#include "../../../utils/HitboxManager/CaptainAmericaProjectileHitboxManager/CaptainAmericaProjectileHitboxManager.h"
#include "../../../utils/HitboxManager/SpiderManProjectileHitboxManager/SpiderManProjectileHitboxManager.h"
#include "../../../utils/HitboxManager/ChunLiProjectileHitboxManager/ChunLiProjectileHitboxManager.h"
#include "../../../utils/HitboxManager/VenomProjectileHitboxManager/VenomProjectileHitboxManager.h"


GameObjectServerFactory::GameObjectServerFactory(int screenWidth_, int screenHeight_) {

    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}

GameObjectServerFactory::~GameObjectServerFactory() = default;


vector<GameObject_server *> GameObjectServerFactory::getGameObjectsServerCharacters_fight() {

    vector<GameObject_server*>  gameObjects;
    CLogger* logger = CLogger::GetLogger();

    map<string, HitboxManager*> hitboxManager;
    map<string, HitboxManager*>::iterator itrHitbox;

    map<string, HitboxManager*> projectileHitboxManager;


    hitboxManager["CaptainAmerica"] = new CaptainAmericaHitboxManager();
    hitboxManager["SpiderMan"] = new SpiderManHitboxManager();
    hitboxManager["ChunLi"] = new ChunLiHitboxManager();
    hitboxManager["Venom"] = new VenomHitboxManager();

    projectileHitboxManager["CaptainAmerica"] = new CaptainAmericaProjectileHitboxManager();
    projectileHitboxManager["SpiderMan"] = new SpiderManProjectileHitboxManager();
    projectileHitboxManager["ChunLi"] = new ChunLiProjectileHitboxManager();
    projectileHitboxManager["Venom"] = new VenomProjectileHitboxManager();

    JsonConfigs* config = JsonConfigs::getJson();
    std::list<JsonCharacter> characters = config->getCharacters();

    list <JsonCharacter>::iterator iter = characters.begin();

    //CARGA DE DATOS DE LOS PERSONAJES DESDE JSON Y CREACION DE LOS MISMOS
    for (iter ;iter != characters.end();++iter) {

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int initialY = screenHeight - height;
        string name = (*iter).getName();
        int wSprite = (*iter).getWSprite();
        int hSprite = (*iter).getHSprite();

        itrHitbox = hitboxManager.find(name);
        HitboxManager* hitbox = itrHitbox->second;

        HitboxManager* projectileHitbox = projectileHitboxManager[name];

        Character_server* projectile;

        if (name == "CaptainAmerica"){
            projectile = new Character_server(485, "projectileCA", 148, 48, projectileHitbox, 322, 245, NULL);
        }
        else if (name == "SpiderMan"){
            projectile = new Character_server(538, "projectileSM", 145, 48, projectileHitbox, 491, 268, NULL);
        }
        else if (name == "ChunLi"){
            projectile = new Character_server(463, "projectileCL", 143, 75, projectileHitbox, 407, 210, NULL);
        }
        else if (name == "Venom"){
            projectile = new Character_server(435, "projectileV", 127, 33, projectileHitbox, 560, 238, NULL);
        }

        Character_server* C = new Character_server(initialY, name, width, height, hitbox, wSprite, hSprite, projectile);

        C->setInitialXPositions(width/2, (screenWidth - width) - (width/2));
        gameObjects.push_back((C));
    }

    return gameObjects;

}





vector<GameObject_server *> GameObjectServerFactory::getGameObjectsServerBackgrounds_fight() {

    CLogger* logger = CLogger::GetLogger();
    vector<GameObject_server *> gameObjects;
    JsonConfigs* config = JsonConfigs::getJson();
    list <JsonBackground> battlefields = config->getJsonBackgrounds();

    int maxWidth = 0;
    int speedCharacter = config->getCharactersSpeed();

    list <JsonBackground>::iterator iter = battlefields.begin();
    for (iter ;iter != battlefields.end();++iter){

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        string name = (*iter).getName();

        //HARCODEO EL NOMBRE, PQ NO LO USAMOS, ¿ES UNA MALA DECISIÓN? SI, LO ES, PERO ASÍ ES LA VIDA.
        Background_server *B = new Background_server(name, width, height, screenWidth, screenHeight);

        if (width > maxWidth) maxWidth = width;

        gameObjects.push_back(B);
    }

    vector <GameObject_server*>::iterator itr = gameObjects.begin();

    for (itr; itr != gameObjects.end(); ++itr){

        vector<int> info = (*itr)->getInfo();
        double speedPercentageB = cameraSpeedPercentage(maxWidth, info[0]);
        int cameraSpeedB = speedCharacter * speedPercentageB;
        dynamic_cast<Background_server*>(*itr)->setSpeeds(cameraSpeedB,speedPercentageB);
    }


    return gameObjects;
}

double GameObjectServerFactory::cameraSpeedPercentage(int widthMax, int widthImg) {

    double a = widthImg - screenWidth;
    double b = widthMax - screenWidth;
    return a/b;
}





