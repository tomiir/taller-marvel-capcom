//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

GameObjectFactory::~GameObjectFactory() = default;


vector<GameObject*> GameObjectFactory:: getGameObjectsCharacters_fight() {

    vector<GameObject*>  gameObjects;

    Character* captainAmerica = new Character("/home/magali/Documents/taller/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* wolverine = new Character("/home/magali/Documents/taller/taller-marvel-capcom/Images/capComSprites/capCom_walk_1.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* captainAmerica2= new Character("/home/magali/Documents/taller/taller-marvel-capcom/Images/CaptainAmerica2.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* wolverine2 = new Character("/home/magali/Documents/taller/taller-marvel-capcom/Images/capComSprites/capCom_walk_1.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);

    gameObjects = {captainAmerica, wolverine, captainAmerica2, wolverine2};

    return gameObjects;

}

vector<GameObject*> GameObjectFactory:: getGameObjectsBackgrounds_fight() {

    vector<GameObject *> gameObjects;


    Background *B1 = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Background1.png",
                                    renderer, 1500, 900, 1200, 700);
    if (!B1) {
//lanzar excepcion
    }

    Background *B2 = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Background2.png",
                                    renderer, 1900, 900, 1200, 700);
    if (!B2) {
//lanzar excepcion
    }

    Background *B3 = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Background2.png",
                                    renderer, 2300, 900, 1200, 700);
    if (!B3) {
//lanzar excepcion
    }

    gameObjects = {B1, B2, B3};

}