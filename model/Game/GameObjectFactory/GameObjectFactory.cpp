//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmerica/CaptainAmericaSpriteManager.h"
#include "../../../utils/SpriteManagers/China/ChinaSpriteManager.h"

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

GameObjectFactory::~GameObjectFactory() = default;


vector<GameObject*> GameObjectFactory:: getGameObjects_fight() {

    vector<GameObject*>  gameObjects;

    //Character* character = new Character("Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* character = new Character("Images/ChinaSprites.png", renderer, new ChinaSpriteManager(), 800,450,200,300);


    Background* B1 = new Background("Images/Backgrounds/Background1.png", renderer, 1500, 900, 1200, 700);
    if (!B1) {
        //lanzar excepcion
    }

    Background* B2 = new Background("Images/Backgrounds/Background2.png", renderer, 1900, 900, 1200, 700);
    if (!B2) {
        //lanzar excepcion
    }

    Background* B3 = new Background("Images/Backgrounds/Background3.png", renderer, 2300, 900, 1200, 700);
    if (!B3) {
        //lanzar excepcion
    }

    gameObjects = {B1, B2, B3, character };


    return gameObjects;

}



