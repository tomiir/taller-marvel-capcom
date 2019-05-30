//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"

GameObjectControllerFactory::GameObjectControllerFactory(int screenWidth_, int screenHeight_, int speedCharacter_, int jumpSpeed_){

    factory = new GameObjectServerFactory(screenWidth_, screenHeight_);
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
    speedCharacter = speedCharacter_;
    jumpSpeed = jumpSpeed_;
}

GameObjectControllerFactory::~GameObjectControllerFactory() = default;


std::vector<ControllerCharacter*> GameObjectControllerFactory::getControllersCharacter_fight(){

    vector<GameObject_server*> gameObjects = factory->getGameObjectsServerCharacters_fight();
    vector <ControllerCharacter*> characters;

    //hardcodeo los z indexs
    ControllerCharacter* controllerCharacter1 = new ControllerCharacter(gameObjects[0], screenWidth, screenHeight, speedCharacter, jumpSpeed);
    ControllerCharacter* controllerCharacter2 = new ControllerCharacter(gameObjects[1], screenWidth, screenHeight, speedCharacter, jumpSpeed);
    ControllerCharacter* controllerCharacter3 = new ControllerCharacter(gameObjects[2], screenWidth, screenHeight, speedCharacter, jumpSpeed);
    ControllerCharacter* controllerCharacter4 = new ControllerCharacter(gameObjects[3], screenWidth, screenHeight, speedCharacter, jumpSpeed);


    characters = { controllerCharacter1, controllerCharacter2,controllerCharacter3,controllerCharacter4 };

    delete factory;

    return characters;
}

std::vector<ControllerBackground*> GameObjectControllerFactory::getControllersBackground_fight(){

    vector<GameObject_server*> gameObjects = factory->getGameObjectsServerBackgrounds_fight();
    vector <ControllerBackground*> backgrounds;


    ControllerBackground* controllerB1 = new ControllerBackground(gameObjects[0], jumpSpeed);
    ControllerBackground* controllerB2 = new ControllerBackground(gameObjects[1], jumpSpeed);
    ControllerBackground* controllerB3 = new ControllerBackground(gameObjects[2], jumpSpeed);


    backgrounds = { controllerB1, controllerB2, controllerB3 };
    return backgrounds;
}