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
#include "../../../utils/AudioManager/CaptainAmericaAudioManager/CaptainAmericaAudioManager.h"
#include "../../../utils/AudioManager/SpiderManAudioManager/SpiderManAudioManager.h"
#include "../../../utils/AudioManager/VenomAudioManager/VenomAudioManager.h"
#include "../../../utils/AudioManager/ChunLiAudioManager/ChunLiAudioManager.h"
#include "../../../utils/SpriteManagers/CaptainAmericaProjectileSpriteManager/CaptainAmericaProjectileSpriteManager.h"
#include "../../../utils/SpriteManagers/SpiderManProjectileSpriteManager/SpiderManProjectileSpriteManager.h"
#include "../../../utils/SpriteManagers/ChunLiProjectileSpriteManager/ChunLiProjectileSpriteManager.h"
#include "../../../utils/SpriteManagers/VenomProjectileSpriteManager/VenomProjectileSpriteManager.h"
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


    map<string, AudioManager*> audioManagers;
    map<string, SpriteManager*> spriteManagers;
    map<string, SpriteManager*> projectileManagers;

    spriteManagers["CaptainAmerica"] = new CaptainAmericaSpriteManager();
    spriteManagers["SpiderMan"] = new SpiderManSpriteManager();
    spriteManagers["Venom"] = new VenomSpriteManager();
    spriteManagers["ChunLi"] = new ChunLiSpriteManager();
    spriteManagers["NotFound"] = new NotFoundSpriteManager();

    audioManagers["CaptainAmerica"] = new CaptainAmericaAudioManager();
    audioManagers["SpiderMan"] = new SpiderManAudioManager();
    audioManagers["Venom"] = new VenomAudioManager();
    audioManagers["ChunLi"] = new ChunLiAudioManager();

    projectileManagers["CaptainAmerica"] = new CaptainAmericaProjectileSpriteManager();
    projectileManagers["SpiderMan"] = new SpiderManProjectileSpriteManager();
    projectileManagers["ChunLi"] = new ChunLiProjectileSpriteManager();
    projectileManagers["Venom"] = new VenomProjectileSpriteManager();

    map<string, SpriteManager*>::iterator itrSprites;
    JsonConfigs* config = JsonConfigs::getJson();
    std::list<JsonCharacter> characters = config->getCharacters();

    list <JsonCharacter>::iterator iter = characters.begin();

    //CARGA DE DATOS DE LOS PERSONAJES DESDE JSON Y CREACION DE LOS MISMOS
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
            path = "../DefaultConfigs/NotFound.png";
            spriteManagerName = "NotFound";
        }

        if(!spriteManagers.count(spriteManagerName)){
            spriteManagerName = name;
            logger -> Log("No se encontró el sprite manager " + spriteManagerName + ", se utilizara el default", ERROR, "");
        }
        itrSprites = spriteManagers.find(spriteManagerName);
        SpriteManager* spriteManager = itrSprites->second;

        AudioManager* audioManager = audioManagers[spriteManagerName]; //Uso el mismo que el spriteManager

        SpriteManager* projectileManager = projectileManagers[spriteManagerName]; //Uso el mismo que el spriteManager

        Character* C;
        Character* projectile;

        //ESTE IF SE SACARIA CUNADO SE LEVANTE DEL JSON Y ESTE LA RUTA DEL PROYECTIL JUNTO A SU PERSONAJE

        if (name == "CaptainAmerica"){
            projectile = new Character("../Images/Characters/proyectilCA.png", 99, renderer, projectileManager, 0, "projectileCA", 2.5, NULL);
        }
        else if (name == "SpiderMan"){
            projectile = new Character("../Images/Characters/proyectilSM.png", 99, renderer, projectileManager, 0, "projectileSM", 2.5, NULL);
        }
        else if (name == "ChunLi"){
            projectile = new Character("../Images/Characters/proyectilCL.png", 99, renderer, projectileManager, 0, "projectileCL", 2.5, NULL);
        }
        else if (name == "Venom"){
            projectile = new Character("../Images/Characters/proyectilV.png", 99, renderer, projectileManager, 0, "projectileV", 2.5, NULL);
        }

        C = new Character(path.c_str(),  zIndex, renderer, spriteManager , initialY, name, size, projectile);
        C->setAudioManager(audioManager);
        C->setInitialXPositions(width/2, (screenWidth - width) - (width/2));

        gameObjects.push_back((C));
    }

    return gameObjects;
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
            path = "../DefaultConfigs/BackgroundNotFound.png";
        }

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int zIndex = (*iter).getzIndex();
        string name = (*iter).getName();

        //HARCODEO EL NOMBRE, PQ NO LO USAMOS, ¿ES UNA MALA DECISIÓN? SI, LO ES, PERO ASÍ ES LA VIDA.
        Background *B = new Background(path.c_str(),name, zIndex, renderer, width, height, screenWidth, screenHeight);
        

        if (width > maxWidth) maxWidth = width;

        gameObjects.push_back(B);
    }


    return gameObjects;

}

vector<GameObject_charSelect *> GameObjectFactory::getgameobjectChar_select_fight() {

    CLogger* logger = CLogger::GetLogger();
    vector<GameObject_charSelect *> gameObjects;
    JsonConfigs* config = JsonConfigs::getJson();
    list <JsonGameObject_charSelect> jsonGameObject = config->getGameObjectCharSelect();

    int aux_y = (screenHeight - 600)/2;
    int aux_x = (screenWidth - 800)/2;
    std::vector<int> aux;

    int i = 0;

    list <JsonGameObject_charSelect>::iterator iter = jsonGameObject.begin();
    for (iter ;iter != jsonGameObject.end();++iter){

        std::string path = (*iter).getFilePath();

        if(!existFile(path.c_str())){
            logger -> Log("No se encontró " + path + ", se utilizara la imagen NotFound", ERROR, "");
            path = "../DefaultConfigs/BackgroundNotFound.png";
        }

        std::vector<int> posc = (*iter).getPosc();
        std::string name = (*iter).getName();

        if (i == 0){
            //FONDO
            aux = {aux_x,aux_y,posc[2],posc[3]};
            GameObject_charSelect* background =  new GameObject_charSelect(path.c_str(),name, 0, renderer, aux );
            gameObjects.push_back(background);
        }
        else if (i <= 18){
            //IMAGENES LATERALES
            GameObject_charSelect* go =  new GameObject_charSelect(path.c_str(),name, 0, renderer, posc );
            gameObjects.push_back(go);

        }

        else{
            aux = {posc[0]+aux_x,posc[1]+aux_y,posc[2],posc[3]};
            GameObject_charSelect* go =  new GameObject_charSelect(path.c_str(),name, 0, renderer, aux );
            gameObjects.push_back(go);
        }

        i++;
    }

    return gameObjects;
}

GameObject *GameObjectFactory::getGameObjectDisconnected() {

    JsonConfigs* config = JsonConfigs::getJson();
    JsonDisconection disconection = config->getJsonDisconection();
    string path = disconection.getPath();
    int zIndex = disconection.getZ_index();
    string name = disconection.getName();
    int initialX = (disconection.getWidth() - screenWidth)/2;
    int initialY = (disconection.getHeight() - screenHeight)/2;


    GameObject *disconnected = new GameObject(path.c_str(),name, zIndex, renderer, initialX, initialY, screenWidth, screenHeight);

    return  disconnected;
}
/*
 * EL TEAM 2 ES EL DE LA DERECHA (FRAMES DE VIDA), PERO USA ASDWC
 * EL TEAM 1 ES EL DE LA IZQUIERDA  (FRAMES DE VIDA), EL QUE USA JKLIM
*/

LifeManager *GameObjectFactory::getLifeManagerTeam1() {

    GameObject* lifeCaptainAmerica = new GameObject("../Images/life_frame/vida-captainamerica.png","CaptainAmerica",99,renderer ,0,10, 491, 104);
    GameObject* lifeVenom = new GameObject("../Images/life_frame/vida-venom.png","Venom",99,renderer ,0,10, 491, 104);
    GameObject* lifeSpiderMan = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99,renderer ,0,10, 491, 104);
    GameObject* lifeChunLi = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer ,0,10, 491, 104);

    vector <int> sourcePositionPrimary = {10,12,491,104};
    vector <int> destinyPositionPrimary = {0,10, 491, 104};
    vector <int> sourcePositionSecondary = {10,143,258,55};
    vector <int> destinyPositionSecondary = {0, 110, 258, 55};

    map <string, GameObject*> lifeFrames;
    lifeFrames["CaptainAmerica"]  = lifeCaptainAmerica;
    lifeFrames["Venom"] = lifeVenom;
    lifeFrames["SpiderMan"] = lifeSpiderMan;
    lifeFrames["ChunLi"] = lifeChunLi;


    // se debe completar con el x y w h del rectángulo de la barra de vida
    vector <int> colorLifePositionPrimary = {87,32,397,34};
    vector <int> colorLifePositionSecond = {46,124,208,17};
    LifeManager* lifeManager = new LifeManager(renderer,50,colorLifePositionPrimary, colorLifePositionSecond,
                                               sourcePositionPrimary, destinyPositionPrimary, sourcePositionSecondary, destinyPositionSecondary);

    lifeManager->addCharacters(lifeFrames);

    return lifeManager;
}

LifeManager *GameObjectFactory::getLifeManagerTeam2() {

    GameObject* lifeCaptainAmerica = new GameObject("../Images/life_frame/vida-captainamerica.png","CaptainAmerica",99,renderer, 710, 10, 489, 104);
    GameObject* lifeVenom = new GameObject("../Images/life_frame/vida-venom.png","Venom",99,renderer, 710, 10, 489, 104);
    GameObject* lifeSpiderMan = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99,renderer, 710, 10, 489, 104);
    GameObject* lifeChunLi = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer, 710, 10, 489, 104);


    vector<int> sourcePositionPrimary =  {507,12,489,104};
    vector<int> destinyPositionPrimary =  {710, 10, 489, 104};

    vector<int> sourcePositionSecondary =  {739,143, 257, 55};
    vector<int> destinyPositionSecondary = { 943,105, 257,55};

    map <string, GameObject*> lifeFrames;
    lifeFrames["CaptainAmerica"]  = lifeCaptainAmerica;
    lifeFrames["Venom"] = lifeVenom;
    lifeFrames["SpiderMan"] = lifeSpiderMan;
    lifeFrames["ChunLi"] = lifeChunLi;

    // se debe completar con el x y w h del rectángulo de la barra de vida
    vector <int> colorLifePositionPrimary = {716,32,394,31};
    vector <int> colorLifePositionSecond = {946,124,208,17};
    LifeManager* lifeManager = new LifeManager(renderer,50,colorLifePositionPrimary, colorLifePositionSecond,
            sourcePositionPrimary, destinyPositionPrimary, sourcePositionSecondary, destinyPositionSecondary );
    lifeManager->setAsRight();
    lifeManager->addCharacters(lifeFrames);

    return lifeManager;
}

TimeManager *GameObjectFactory::getTimeManager() {

    GameObject* unity  = new GameObject("../Images/timer/timer-rounds.png","unity",99,renderer, 591, 10, 60, 60);
    GameObject* ten = new GameObject("../Images/timer/timer-rounds.png","ten",99,renderer, 555, 10, 60, 60);
    int xRound = (screenWidth - 258*2)/2;
    int yRound = (screenHeight - 91*2)/2;
    GameObject* roundFight = new GameObject("../Images/timer/timer-rounds.png","timeRound",99,renderer, xRound, yRound,  258*2, 91*2);

    map <int, vector<int>> positionSource;
    positionSource[0] = {0,0, 60, 60};
    positionSource[1] = {60,0, 60, 60};
    positionSource[2] = {120,0, 60, 60};
    positionSource[3] = {180,0, 60, 60};
    positionSource[4] = {240,0, 60, 60};
    positionSource[5] = {300,0, 60, 60};
    positionSource[6] = {360,0, 60, 60};
    positionSource[7] = {420,0, 60, 60};
    positionSource[8] = {480,0, 60, 60};
    positionSource[9] = {540,0, 60, 60};
    positionSource[10] = {0,60, 258,91}; // EN LA POSICIÓN 10 ESTÁ EL ROUND 1
    positionSource[11] = {0,152, 258,91}; // EN LA POSICIÓN 11 ESTA EL ROUND 2
    positionSource[12] = {0,244,258,91}; // EN LA POSICIÓN 12 ESTÁ EL ROUND 3
    positionSource[13] = {297,84,257,115}; // EN LA POSICIÓN 13 ESTÁ EL FIGHT


    TimeManager* timeManager = new TimeManager(99, unity, ten, roundFight, positionSource);
    return timeManager;
}

vector<GameObject *> GameObjectFactory::getGameObject_endGame() {

    vector<int> positionToTake;

    /*
     * a: captain america
     * c: chunli
     * v: venom
     * s: spiderMan
     * Posibilidades:
     * ac
     * av
     * as
     * cv
     * cs
     * vs
    */

    GameObject* background    = new GameObject("../Images/winner/WinnerBackground.png","background",99,renderer, 0, 0, 1200 ,700);

    GameObject* ac    = new GameObject("../Images/winner/WinnerTeam.png","ac",99,renderer, 0, 394, 1200,306);
    positionToTake = {0,0, 1200, 306};
    ac->setOriginRect(positionToTake);

    GameObject* av    = new GameObject("../Images/winner/WinnerTeam.png","av",99,renderer, 0, 394, 1200,306);
    positionToTake = {0,612, 1200, 306};
    av->setOriginRect(positionToTake);

    GameObject* as  = new GameObject("../Images/winner/WinnerTeam.png","as",99,renderer, 0, 394, 1200,306);
    positionToTake = {0, 918,1200, 306};
    as->setOriginRect(positionToTake);

    GameObject* cv  = new GameObject("../Images/winner/WinnerTeam.png", "cv",99,renderer, 0, 394, 1200,306);
    positionToTake = {0,1224, 1200, 306};
    cv->setOriginRect(positionToTake);

    GameObject* cs  = new GameObject("../Images/winner/WinnerTeam.png","cs",99,renderer, 0, 394, 1200,306);
    positionToTake = {0, 1530, 1200, 306};
    cs->setOriginRect(positionToTake);

    GameObject* vs  = new GameObject("../Images/winner/WinnerTeam.png","sv",99,renderer, 0, 394, 1200,306);
    positionToTake = {0,306, 1200, 306};
    vs->setOriginRect(positionToTake);

    GameObject* ilumination  = new GameObject("../Images/winner/Ilumination.png","ilumination",99,renderer, 0, 0, 1200,700);
    positionToTake = {0,0, 1200, 700};
    ilumination->setOriginRect(positionToTake);

    vector<GameObject *> gameObjects = {background, ac, av, as, cv, cs, vs, ilumination};
    return gameObjects ;
}



int GameObjectFactory::getYCenter(int height) {
    return (screenHeight - height*2)/2;
}

int GameObjectFactory::getXCenter(int width) {
    return(screenWidth - width*2)/2;
}
