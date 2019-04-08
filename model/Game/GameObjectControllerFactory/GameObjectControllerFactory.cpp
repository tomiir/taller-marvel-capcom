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

std::vector<Controller*> GameObjectControllerFactory::getGameObjectControllers_fight(){

    vector<GameObject*> gameObjects = factory->getGameObjects_fight();
    vector <Controller*> controllers;

    int speedCharacter = 10;
    int widthMax = 2300;

    double speedPercentageB1 = cameraSpeedPercentage(widthMax, 1500);
    double speedPercentageB2 = cameraSpeedPercentage(widthMax, 1900);
    double speedPercentageB3 = cameraSpeedPercentage(widthMax, 2300);

    int cameraSpeedB1 = speedCharacter * speedPercentageB1;
    int cameraSpeedB2 = speedCharacter * speedPercentageB2;
    int cameraSpeedB3 = speedCharacter * speedPercentageB3;

    // ¿habría que hacer controllers distintos para background y character?

    //ControllerCharacter* controllerCharacter2 = new ControllerCharacter(gameObjects[4], 1200, 700, 30);
    ControllerCharacter* controllerCharacter1 = new ControllerCharacter(gameObjects[3], 1200, 700, speedCharacter); //ver tema pasar info size ventana.

    ControllerBackground* controllerB1 = new ControllerBackground(gameObjects[0], controllerCharacter1, cameraSpeedB1, speedPercentageB1); //porque solo le paso un unico character?
    ControllerBackground* controllerB2 = new ControllerBackground(gameObjects[1], controllerCharacter1, cameraSpeedB2, speedPercentageB2);
    ControllerBackground* controllerB3 = new ControllerBackground(gameObjects[2], controllerCharacter1, cameraSpeedB3, speedPercentageB3);


    controllers = { controllerB1, controllerB2, controllerB3, controllerCharacter1};

    return controllers;
}

