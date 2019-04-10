//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"
#include "../../../utils/SpriteManagers/CaptainAmericaSpriteManager/CaptainAmericaSpriteManager.h"
#include "../../../utils/SpriteManagers/VenomSpriteManager/VenomSpriteManager.h"

GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

GameObjectFactory::~GameObjectFactory() = default;


vector<GameObject*> GameObjectFactory:: getGameObjectsCharacters_fight() {

    vector<GameObject*>  gameObjects;

    Character* captainAmerica = new Character("Images/CaptainAmerica.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* venom1 = new Character("Images/Venom.png", renderer, new VenomSpriteManager(), 800,400,200,300);
    Character* captainAmerica2= new Character("Images/CaptainAmerica.png", renderer, new CaptainAmericaSpriteManager(), 800,400,200,300);
    Character* venom2 = new Character("Images/Venom.png", renderer, new VenomSpriteManager(), 800,400,200,300);

    gameObjects = {captainAmerica, venom1, captainAmerica2, venom2};

    return gameObjects;

}

vector<GameObject*> GameObjectFactory:: getGameObjectsBackgrounds_fight() {

    vector<GameObject *> gameObjects;


    Background *B1 = new Background("Images/Backgrounds/Background1.png", renderer, 1500, 900, 1200, 700);
    if (!B1) {
//lanzar excepcion
    }

    Background *B2 = new Background("Images/Backgrounds/Background2.png", renderer, 1900, 900, 1200, 700);
    if (!B2) {
//lanzar excepcion
    }

    Background *B3 = new Background("Images/Backgrounds/Background3.png", renderer, 2300, 900, 1200, 700);
    if (!B3) {
//lanzar excepcion
    }

    gameObjects = {B1, B2, B3};
    return gameObjects;

}