//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"
#include "../../../utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.h"
#include "../../../utils/SpriteManagers/SpiderManSpriteManager/SpiderManSpriteManager.h"
#include "../../../utils/SpriteManagers/ChunLiSpriteManager/ChunLiSpriteManager.h"


GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_) {

    renderer = renderer_;
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;

}

GameObjectFactory::~GameObjectFactory() = default;


vector<GameObject*> GameObjectFactory:: getGameObjectsCharacters_fight() {

    vector<GameObject*>  gameObjects;


    Character* captainAmerica = new Character("Images/CaptainAmerica.png",5, renderer, new CaptainAmericaSpriteManager(), 200/2, screenHeight - 280, screenHeight - 280 + 75);
    Character* chunLi = new Character("Images/ChunLi.png",5, renderer, new ChunLiSpriteManager(), 200/2,screenHeight - 220, screenHeight - 220 + 40);

    Character* spiderMan= new Character("Images/SpiderMan.png",4, renderer, new SpiderManSpriteManager(), (screenWidth - 200) - (200/2),screenHeight - 245, screenHeight - 245 + 95);
    Character* venom = new Character("Images/Venom.png",4, renderer, new VenomSpriteManager(), (screenWidth - 200) - (200/2), screenHeight - 280, screenHeight - 280 + 60);


    gameObjects = {spiderMan, venom, captainAmerica, chunLi};


    return gameObjects;

}

vector<GameObject*> GameObjectFactory:: getGameObjectsBackgrounds_fight() {

    vector<GameObject *> gameObjects;



    Background *B1 = new Background("Images/Backgrounds/Background1.png",1, renderer, 1500, 900, screenWidth, screenHeight);

    if (!B1) {
//lanzar excepcion
    }


    Background *B2 = new Background("Images/Backgrounds/Background2.png",2, renderer, 1900, 900, screenWidth, screenHeight);

    if (!B2) {
//lanzar excepcion
    }

   
    Background *B3 = new Background("Images/Backgrounds/Background3.png",3, renderer, 2300, 900, screenWidth, screenHeight);

    if (!B3) {
//lanzar excepcion
    }

    gameObjects = {B1, B2, B3};
    return gameObjects;

}