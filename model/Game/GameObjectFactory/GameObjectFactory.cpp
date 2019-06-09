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

        Character* C;

        C = new Character(path.c_str(), spriteManagerName,  zIndex, renderer, spriteManager , initialY, name, size);

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
    vector <int> infoSource = {10,12,491,104};
    lifeCaptainAmerica->setOriginRect(infoSource);

    GameObject* lifeVenom = new GameObject("../Images/life_frame/vida-venom.png","Venom",99,renderer ,0,10, 491, 104);
    lifeVenom->setOriginRect(infoSource);

    GameObject* lifeSpiderMan = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99,renderer ,0,10, 491, 104);
    lifeSpiderMan->setOriginRect(infoSource);

    GameObject* lifeChunLi = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer ,0,10, 491, 104);
    lifeChunLi->setOriginRect(infoSource);

    vector <GameObject*> lifeFrames = {lifeCaptainAmerica,
                                       lifeVenom,
                                       lifeSpiderMan,
                                       lifeChunLi};


    GameObject* lifeCaptainAmericaSecond = new GameObject("../Images/life_frame/vida-captainamerica.png","CaptainAmerica",99, renderer, 0, 143, 258, 55);
    infoSource = {10,133,258,55};
    lifeCaptainAmericaSecond->setOriginRect(infoSource);

    GameObject* lifeVenomSecond = new GameObject("../Images/life_frame/vida-venom.png","Venom",99, renderer, 0, 143, 258, 55);
    infoSource = {10,133,258,55};
    lifeVenomSecond->setOriginRect(infoSource);

    GameObject* lifeSpiderManSecond = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99,renderer, 0, 143, 258, 55);
    infoSource = {10,133,258,55};
    lifeSpiderManSecond->setOriginRect(infoSource);

    GameObject* lifeChunLiSecond = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer, 0, 143, 258, 55);
    infoSource = {10,133,258,55};
    lifeChunLiSecond->setOriginRect(infoSource);

    vector <GameObject*> lifeFramesSecond = {lifeCaptainAmericaSecond,
                                       lifeVenomSecond,
                                       lifeSpiderManSecond,
                                       lifeChunLiSecond};
    // se debe completar con el x y w h del rectángulo de la barra de vida
    vector <int> aux1 = {87,32,397,34};
    vector <int> aux2 = {46,167,208,17};
    LifeManager* lifeManager = new LifeManager(renderer,50,aux1, aux2);

    lifeManager->addCharacters(lifeFrames);
    lifeManager->addCharactersSecond(lifeFramesSecond);

    return lifeManager;
}

LifeManager *GameObjectFactory::getLifeManagerTeam2() {

    GameObject* lifeCaptainAmerica = new GameObject("../Images/life_frame/vida-captainamerica.png","CaptainAmerica",99,renderer, 710, 10, 489, 104);
    vector <int> aux= {507,12,489,104};
    lifeCaptainAmerica->setOriginRect(aux);

    GameObject* lifeVenom = new GameObject("../Images/life_frame/vida-venom.png","Venom",99,renderer, 710, 10, 489, 104);
    aux= {507,12,489,104};
    lifeVenom->setOriginRect(aux);

    GameObject* lifeSpiderMan = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99,renderer, 710, 10, 489, 104);
    aux= {507,12,489,104};
    lifeSpiderMan->setOriginRect(aux);

    GameObject* lifeChunLi = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer, 710, 10, 489, 104);
    aux= {507,12,489,104};
    lifeChunLi->setOriginRect(aux);

    vector <GameObject*> lifeFrames = {lifeCaptainAmerica,
                                       lifeVenom,
                                       lifeSpiderMan,
                                       lifeChunLi};


    GameObject* lifeCaptainAmericaSecond = new GameObject("../Images/life_frame/vida-captainamerica.png","CaptainAmerica",99,renderer, 943,143, 257,55);
    aux = {739,133, 257, 55};
    lifeCaptainAmericaSecond->setOriginRect(aux);

    GameObject* lifeVenomSecond = new GameObject("../Images/life_frame/vida-venom.png","Venom",99, renderer, 943,143, 257,55);
    aux = {739,133, 257, 55};
    lifeVenomSecond->setOriginRect(aux);

    GameObject* lifeSpiderManSecond = new GameObject("../Images/life_frame/vida-spiderman.png","SpiderMan",99, renderer, 943,143, 257,55);
    aux = {739,133, 257, 55};
    lifeSpiderManSecond->setOriginRect(aux);

    GameObject* lifeChunLiSecond = new GameObject("../Images/life_frame/vida-chunli.png","ChunLi",99,renderer, 943,143, 257,55);
    aux = {739,133, 257, 55};
    lifeChunLiSecond->setOriginRect(aux);

    vector <GameObject*> lifeFramesSecond = {lifeCaptainAmericaSecond,
                                             lifeVenomSecond,
                                             lifeSpiderManSecond,
                                             lifeChunLiSecond};

    // se debe completar con el x y w h del rectángulo de la barra de vida
    vector <int> aux1 = {716,32,394,31};
    vector <int> aux2 = {946,167,208,17};
    LifeManager* lifeManager = new LifeManager(renderer,50,aux1, aux2);
    lifeManager->setAsRight();
    lifeManager->addCharacters(lifeFrames);
    lifeManager->addCharactersSecond(lifeFramesSecond);
    return lifeManager;
}

TimeManager *GameObjectFactory::getTimeManager() {

    GameObject* unityZero   = new GameObject("../Images/timer/timer-rounds.png","unityZero",99,renderer, 600, 10, 60, 60);
    vector <int> positionToTake = {0,0, 60, 60};
    unityZero->setOriginRect(positionToTake);
    GameObject* unityOne    = new GameObject("../Images/timer/timer-rounds.png","unityOne",99,renderer, 600, 10, 60, 60);
    positionToTake = {60,0, 60, 60};
    unityOne->setOriginRect(positionToTake);
    GameObject* unityTwo    = new GameObject("../Images/timer/timer-rounds.png","unityTwo",99,renderer, 600, 10, 60, 60);
    positionToTake = {120,0, 60, 60};
    unityTwo->setOriginRect(positionToTake);
    GameObject* unityThree  = new GameObject("../Images/timer/timer-rounds.png","unityThree",99,renderer, 600, 10, 60, 60);
    positionToTake = {180,0, 60, 60};
    unityThree->setOriginRect(positionToTake);
    GameObject* unityFour   = new GameObject("../Images/timer/timer-rounds.png","unityFour",99,renderer, 600, 10, 60, 60);
    positionToTake = {240,0, 60, 60};
    unityFour->setOriginRect(positionToTake);
    GameObject* unityFive   = new GameObject("../Images/timer/timer-rounds.png","unityFive",99,renderer, 600, 10, 60, 60);
    positionToTake = {300,0, 60, 60};
    unityFive->setOriginRect(positionToTake);
    GameObject* unitySix    = new GameObject("../Images/timer/timer-rounds.png","unitySix",99,renderer, 600, 10, 60, 60);
    positionToTake = {360,0, 60, 60};
    unitySix->setOriginRect(positionToTake);
    GameObject* unitySeven  = new GameObject("../Images/timer/timer-rounds.png","unitySeven",99,renderer, 600, 10, 60, 60);
    positionToTake = {420,0, 60, 60};
    unitySeven->setOriginRect(positionToTake);
    GameObject* unityEight  = new GameObject("../Images/timer/timer-rounds.png","unityEight",99,renderer, 600, 10, 60, 60);
    positionToTake = {480,0, 60, 60};
    unityEight->setOriginRect(positionToTake);
    GameObject* unityNine   = new GameObject("../Images/timer/timer-rounds.png","unityNine",99,renderer, 600, 10, 60, 60);
    positionToTake = {540,0, 60, 60};
    unityNine->setOriginRect(positionToTake);

    vector <GameObject*> unityNumbers = {unityZero, unityOne, unityTwo, unityThree,
                                         unityFour, unityFive, unitySix, unitySeven,
                                         unityEight, unityNine};

    GameObject* tenZero     = new GameObject("../Images/timer/timer-rounds.png","tenZero",99,renderer, 540, 10, 60, 60);
    positionToTake= {60,0,  60, 60};
    tenZero->setOriginRect(positionToTake);
    GameObject* tenOne      = new GameObject("../Images/timer/timer-rounds.png","tenOne",99,renderer, 540, 10,  60, 60);
    positionToTake = {120,0,  60, 60};
    tenOne->setOriginRect(positionToTake);
    GameObject* tenTwo      = new GameObject("../Images/timer/timer-rounds.png","tenTwo",99,renderer, 540, 10, 60, 60);
    positionToTake = {180,0,  60, 60};
    tenTwo->setOriginRect(positionToTake);
    GameObject* tenThree    = new GameObject("../Images/timer/timer-rounds.png","tenThree",99,renderer, 540, 10,  60, 60);
    positionToTake = {240,0,  60, 60};
    tenThree->setOriginRect(positionToTake);
    GameObject* tenFour     = new GameObject("../Images/timer/timer-rounds.png","tenFour",99,renderer, 540, 10,  60, 60);
    positionToTake = {300,0,  60, 60};
    tenFour->setOriginRect(positionToTake);
    GameObject* tenFive     = new GameObject("../Images/timer/timer-rounds.png","tenFive",99,renderer, 540, 10,  60, 60);
    positionToTake = {360,0,  60, 60};
    tenFive->setOriginRect(positionToTake);
    GameObject* tenSix      = new GameObject("../Images/timer/timer-rounds.png","tenSix",99,renderer, 540, 10,  60, 60);
    positionToTake = {420,0,  60, 60};
    tenSix->setOriginRect(positionToTake);
    GameObject* tenSeven    = new GameObject("../Images/timer/timer-rounds.png","tenSeven",99,renderer, 540, 10,  60, 60);
    positionToTake = {480,03,  60, 60};
    tenSeven->setOriginRect(positionToTake);
    GameObject* tenEight    = new GameObject("../Images/timer/timer-rounds.png","tenEight",99,renderer, 540, 10, 60, 60);
    positionToTake = {739,133,  60, 60};
    tenEight->setOriginRect(positionToTake);
    GameObject* tenNine     = new GameObject("../Images/timer/timer-rounds.png","tenNine",99,renderer, 540, 10, 60, 60);
    positionToTake = {540,0,  60, 60};
    tenNine->setOriginRect(positionToTake);

    vector <GameObject*> tenNumbers = {tenZero, tenOne, tenTwo, tenThree,
                                       tenFour, tenFive, tenSix, tenSeven,
                                       tenEight, tenNine};

    GameObject* roundOne    = new GameObject("../Images/timer/timer-rounds.png","roundOne",99,renderer, 490, 80, 258,91);
    positionToTake = {0,60, 258,91};
    roundOne->setOriginRect(positionToTake);
    GameObject* roundTwo    = new GameObject("../Images/timer/timer-rounds.png","roundTwo",99,renderer, 490, 80, 258,91);
    positionToTake = {0,318, 258,91};
    roundTwo->setOriginRect(positionToTake);
    GameObject* roundThree  = new GameObject("../Images/timer/timer-rounds.png","roundThree",99,renderer, 490, 80, 258,91);
    positionToTake = {0,576,258,91};
    roundThree->setOriginRect(positionToTake);

    vector <GameObject*> rounds = {roundOne, roundTwo, roundThree};

    TimeManager* timeManager = new TimeManager(99, unityNumbers, tenNumbers, rounds);

    return timeManager;
}
