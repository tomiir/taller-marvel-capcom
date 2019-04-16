//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"

GameObjectControllerFactory::GameObjectControllerFactory(SDL_Renderer *renderer, int screenWidth_, int screenHeight_){

    factory = new GameObjectFactory(renderer, screenWidth_, screenHeight_);
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}

GameObjectControllerFactory::~GameObjectControllerFactory() = default;


std::vector<ControllerCharacter*> GameObjectControllerFactory::getControllersCharacter_fight(){

    vector<GameObject*> gameObjects = factory->getGameObjectsCharacters_fight();
    vector <ControllerCharacter*> characters;

    //hardcodeo los z indexs
    ControllerCharacter* controllerCharacter1 = new ControllerCharacter(gameObjects[0],new EventToValueMapper_player1(), screenWidth, screenHeight, speedCharacter);
    ControllerCharacter* controllerCharacter2 = new ControllerCharacter(gameObjects[1],new EventToValueMapper_player1() ,screenWidth, screenHeight, speedCharacter);
    ControllerCharacter* controllerCharacter3 = new ControllerCharacter(gameObjects[2],new EventToValueMapper_player2(), screenWidth, screenHeight, speedCharacter);
    ControllerCharacter* controllerCharacter4 = new ControllerCharacter(gameObjects[3],new EventToValueMapper_player2() ,screenWidth, screenHeight, speedCharacter);


    characters = { controllerCharacter1, controllerCharacter2,controllerCharacter3,controllerCharacter4 };

    return characters;
}

std::vector<ControllerBackground*> GameObjectControllerFactory::getControllersBackground_fight(){

    vector<GameObject*> gameObjects = factory->getGameObjectsBackgrounds_fight();
    vector <ControllerBackground*> backgrounds;


    ControllerBackground* controllerB1 = new ControllerBackground(gameObjects[0]);
    ControllerBackground* controllerB2 = new ControllerBackground(gameObjects[1]);
    ControllerBackground* controllerB3 = new ControllerBackground(gameObjects[2]);


    backgrounds = { controllerB1, controllerB2, controllerB3 };
    return backgrounds;
}