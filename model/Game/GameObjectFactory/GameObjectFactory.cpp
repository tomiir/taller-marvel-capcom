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

//    vector <GameObject*>::iterator itr = gameObjects.begin();
//
//    for (itr; itr != gameObjects.end(); ++itr){
//
//        vector<int> info = (*itr)->getInfo();
//        double speedPercentageB = cameraSpeedPercentage(maxWidth, info[0]);
//        int cameraSpeedB = speedCharacter * speedPercentageB;
//        dynamic_cast<Background*>(*itr)->setSpeeds(cameraSpeedB,speedPercentageB);
//    }


    return gameObjects;

}

vector<GameObject_charSelect *> GameObjectFactory::getgameobjectChar_select_fight() {

    vector <GameObject_charSelect*> gameObjects;

    vector <int> aux;

    int aux_y = (screenHeight - 600)/2;
    int aux_x = (screenWidth - 800)/2;

    //FONDO
    aux = {aux_x,aux_y,800,600};
    GameObject_charSelect* background =  new GameObject_charSelect("../Images/menu_seleccion/Menu personajes.png","background", 0, renderer, aux );
    gameObjects.push_back(background);


    //IMAGENES LATERALES
    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team1 =  new GameObject_charSelect("../Images/menu_seleccion/SM2.png","SpiderMan", 0, renderer, aux );
    gameObjects.push_back(spider_man_team1);

    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team2 =  new GameObject_charSelect("../Images/menu_seleccion/SM.png","SpiderMan", 0, renderer, aux );
    gameObjects.push_back(spider_man_team2);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_1 =  new GameObject_charSelect("../Images/menu_seleccion/V2.png","Venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_2 =  new GameObject_charSelect("../Images/menu_seleccion/V.png","Venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_2);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_1 =  new GameObject_charSelect("../Images/menu_seleccion/CL2.png","ChunLi", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_2 =  new GameObject_charSelect("../Images/menu_seleccion/CL.png","ChunLi", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_2);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_1 =  new GameObject_charSelect("../Images/menu_seleccion/CA2.png","CaptainAmerica", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_2 =  new GameObject_charSelect("../Images/menu_seleccion/CA.png","CaptainAmerica", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_2);

    //IMAGENES LATERALES seleccionadas
    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team1_selected =  new GameObject_charSelect("../Images/menu_seleccion/SM2.png","SpiderMan", 0, renderer, aux );
    gameObjects.push_back(spider_man_team1_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team2_selected =  new GameObject_charSelect("../Images/menu_seleccion/SM.png","SpiderMan", 0, renderer, aux );
    gameObjects.push_back(spider_man_team2_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_1_selected =  new GameObject_charSelect("../Images/menu_seleccion/V2.png","Venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_1_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_2_selected =  new GameObject_charSelect("../Images/menu_seleccion/V.png","Venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_2_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_1_selected =  new GameObject_charSelect("../Images/menu_seleccion/CL2.png","ChunLi", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_1_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_2_selected =  new GameObject_charSelect("../Images/menu_seleccion/CL.png","ChunLi", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_2_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_1_selected =  new GameObject_charSelect("../Images/menu_seleccion/CA2.png","CaptainAmerica", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_1_selected);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_2_selected =  new GameObject_charSelect("../Images/menu_seleccion/CA.png","CaptainAmerica", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_2_selected);

    //CUADRADITOS
    aux = {200,0,800,600};
    GameObject_charSelect* square_team_1 =  new GameObject_charSelect("../Images/menu_seleccion/Team1 select.png","square_1", 0, renderer, aux );
    gameObjects.push_back(square_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* square_team_2 =  new GameObject_charSelect("../Images/menu_seleccion/Team2 select.png","square_2", 0, renderer, aux );
    gameObjects.push_back(square_team_2);


    //CUADRADITOS GRISES
    aux = {240 + aux_x,296 + aux_y,153,117};
    GameObject_charSelect* square_grey_1=  new GameObject_charSelect("../Images/menu_seleccion/Seleccionado.png","CaptainAmerica", 0, renderer, aux );
    gameObjects.push_back(square_grey_1);

    aux = {403 + aux_x, 296 + aux_y,153,117};
    GameObject_charSelect* square_grey_2=  new GameObject_charSelect("../Images/menu_seleccion/Seleccionado.png","SpiderMan", 0, renderer, aux );
    gameObjects.push_back(square_grey_2);

    aux = {242 + aux_x,422 + aux_y,153,117};
    GameObject_charSelect* square_grey_3 =  new GameObject_charSelect("../Images/menu_seleccion/Seleccionado.png","ChunLi", 0, renderer, aux );
    gameObjects.push_back(square_grey_3);

    aux = {404 + aux_x,422 + aux_y,153,117};
    GameObject_charSelect* square_grey_4=  new GameObject_charSelect("../Images/menu_seleccion/Seleccionado.png","Venom", 0, renderer, aux );
    gameObjects.push_back(square_grey_4);

    return gameObjects;
}
