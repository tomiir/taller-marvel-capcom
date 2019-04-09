//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"


GameObjectControllerFactory::GameObjectControllerFactory(SDL_Renderer *renderer, int screenWidth_, int screenHeight_){

    factory = new GameObjectFactory(renderer);
    screenWidth = screenWidth_;
    screenHeight = screenHeight_;
}

GameObjectControllerFactory::~GameObjectControllerFactory() = default;

double GameObjectControllerFactory::cameraSpeedPercentage(int widthMax, int widthImg) {

    double a = widthImg - screenWidth;
    double b = widthMax - screenWidth;
    return a/b;
}

std::vector<ControllerCharacter*> GameObjectControllerFactory::getCharacterControllers_fight(){ //pasar esto a una lista con un fucking ADD

    std::vector<GameObject*> characters = factory->getCharacters_fight();

    //equipo 1
    ControllerCharacter* controllerCharacter1 = new ControllerCharacter(characters[0], new EventToValueMapper_player1(), 1200, 700, speedCharacter);
    ControllerCharacter* controllerCharacter2 = new ControllerCharacter(characters[1], new EventToValueMapper_player1() ,1200, 700, speedCharacter);
    //equipo 2
    ControllerCharacter* controllerCharacter3 = new ControllerCharacter(characters[2], new EventToValueMapper_player2(), 1200, 700, speedCharacter);
    ControllerCharacter* controllerCharacter4 = new ControllerCharacter(characters[3], new EventToValueMapper_player2() ,1200, 700, speedCharacter);


    std::vector< ControllerCharacter* > controllers = {controllerCharacter1, controllerCharacter2, controllerCharacter3, controllerCharacter4};

    return controllers;
}

BackgroundsController *GameObjectControllerFactory::getBackgroundsController_fight() {

    int widthMax = 2300;

    double speedPercentageB1 = cameraSpeedPercentage(widthMax, 1500);
    double speedPercentageB2 = cameraSpeedPercentage(widthMax, 1900);
    double speedPercentageB3 = cameraSpeedPercentage(widthMax, 2300);

    int cameraSpeedB1 = speedCharacter * speedPercentageB1;
    int cameraSpeedB2 = speedCharacter * speedPercentageB2;
    int cameraSpeedB3 = speedCharacter * speedPercentageB3;

    vector<GameObject*> backgrounds = factory->getBackgrounds_fight();

    BackgroundsController* backgroundsController = new BackgroundsController();

    ControllerBackground* controllerB1 = new ControllerBackground(backgrounds[0], cameraSpeedB1, speedPercentageB1);
    ControllerBackground* controllerB2 = new ControllerBackground(backgrounds[1], cameraSpeedB2, speedPercentageB2);
    ControllerBackground* controllerB3 = new ControllerBackground(backgrounds[2], cameraSpeedB3, speedPercentageB3);

    backgroundsController->addBackgroundController(controllerB1);
    backgroundsController->addBackgroundController(controllerB2);
    backgroundsController->addBackgroundController(controllerB3);

    return backgroundsController;
}

