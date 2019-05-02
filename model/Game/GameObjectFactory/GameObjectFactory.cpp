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


    JsonConfigs* config = new JsonConfigs("configs.json");

    std::list<JsonCharacter> characters = config->getCharacters();


    list <JsonCharacter>::iterator iter = characters.begin();

    for (iter ;iter != characters.end();++iter) {

        std::string path = (*iter).getFilePath();

        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int initialY = screenHeight - height;
        int zIndex = (*iter).getzIndex();
        int crowchedDownYParameter = (*iter).getCrowchedDownY();
        string spriteManagerName = (*iter).getSpriteManager();
        string name = (*iter).getName();
        double size = (*iter).getSize();

        if(!existFile(path.c_str())){
            path = "Images/NotFound.png"; //esto se levanta del json default, tambien aca va el tema logger para este error.
            spriteManagerName = "NotFound";
        }

        itrSprites = spriteManagers.find(spriteManagerName);
        SpriteManager* spriteManager = itrSprites->second;

        if(!spriteManager){

        }

        Character* C;
        if(gameObjects.size() < 2){

            C = new Character(path.c_str(), zIndex, renderer, spriteManager , width/2, initialY, initialY + crowchedDownYParameter, name, size);
        }
        else{
            C = new Character(path.c_str(), zIndex, renderer, spriteManager ,(screenWidth - width) - (width/2), initialY, initialY + crowchedDownYParameter, name, size) ;
        }

        if(!C){
            //lanzar excp
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

    vector<GameObject *> gameObjects;

    JsonConfigs* config = new JsonConfigs("configs.json");

    list <Battlefield> battlefields = config->getBattlefields();

    int maxWidth = 0;
    int speedCharacter = config->getCharactersSpeed();

    list <Battlefield>::iterator iter = battlefields.begin();
    for (iter ;iter != battlefields.end();++iter){

        std::string path = (*iter).getFilePath();
        int width = (*iter).getWidth();
        int height = (*iter).getHeight();
        int zIndex = (*iter).getzIndex();

        Background *B = new Background(path.c_str(), zIndex, renderer, width, height, screenWidth, screenHeight);

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

vector<GameObject_charSelect *> GameObjectFactory::getgameobjectChar_select_fight() {

    vector <GameObject_charSelect*> gameObjects;

    vector <int> aux;

    //FONDO
    aux = {200,0,800,600};
    GameObject_charSelect* background =  new GameObject_charSelect("Images/menu_seleccion/Menu personajes.png","background", 0, renderer, aux );
    gameObjects.push_back(background);


    //IMAGENES LATERALES
    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team1 =  new GameObject_charSelect("Images/menu_seleccion/SM2.png","spider_man", 0, renderer, aux );
    gameObjects.push_back(spider_man_team1);

    aux = {200,0,800,600};
    GameObject_charSelect* spider_man_team2 =  new GameObject_charSelect("Images/menu_seleccion/SM.png","spider_man", 0, renderer, aux );
    gameObjects.push_back(spider_man_team2);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_1 =  new GameObject_charSelect("Images/menu_seleccion/V2.png","venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* venom_team_2 =  new GameObject_charSelect("Images/menu_seleccion/V.png","venom", 0, renderer, aux );
    gameObjects.push_back(venom_team_2);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_1 =  new GameObject_charSelect("Images/menu_seleccion/CL2.png","chun_li", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* chun_li_team_2 =  new GameObject_charSelect("Images/menu_seleccion/CL.png","chun_li", 0, renderer, aux );
    gameObjects.push_back(chun_li_team_2);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_1 =  new GameObject_charSelect("Images/menu_seleccion/CA2.png","cap_america", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* cap_america_team_2 =  new GameObject_charSelect("Images/menu_seleccion/CA.png","cap_america", 0, renderer, aux );
    gameObjects.push_back(cap_america_team_2);


    //CUADRADITOS
    aux = {200,0,800,600};
    GameObject_charSelect* square_team_1 =  new GameObject_charSelect("Images/menu_seleccion/Team1 select.png","square_1", 0, renderer, aux );
    gameObjects.push_back(square_team_1);

    aux = {200,0,800,600};
    GameObject_charSelect* square_team_2 =  new GameObject_charSelect("Images/menu_seleccion/Team2 select.png","square_2", 0, renderer, aux );
    gameObjects.push_back(square_team_2);


    //CUADRADITOS GRISES
    aux = {240,296,153,117};
    GameObject_charSelect* square_grey_1=  new GameObject_charSelect("Images/menu_seleccion/Seleccionado.png","cap_america", 0, renderer, aux );
    gameObjects.push_back(square_grey_1);

    aux = {403, 296,153,117};
    GameObject_charSelect* square_grey_2=  new GameObject_charSelect("Images/menu_seleccion/Seleccionado.png","spider_man", 0, renderer, aux );
    gameObjects.push_back(square_grey_2);

    aux = {242,422,153,117};
    GameObject_charSelect* square_grey_3 =  new GameObject_charSelect("Images/menu_seleccion/Seleccionado.png","chun_li", 0, renderer, aux );
    gameObjects.push_back(square_grey_3);

    aux = {404,422,153,117};
    GameObject_charSelect* square_grey_4=  new GameObject_charSelect("Images/menu_seleccion/Seleccionado.png","venom", 0, renderer, aux );
    gameObjects.push_back(square_grey_4);

    return gameObjects;
}
