//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"


GameObjectControllerFactory::GameObjectControllerFactory(SDL_Renderer *renderer){
    factory = new GameObjectFactory(renderer);
}

std::vector<Controller*> GameObjectControllerFactory::getGameObjectControllers_fight(){

    vector<GameObject*> gameObjects = factory->getGameObjects_fight();
    vector <Controller*> controllers;
    
    // ¿habría que hacer controllers distintos para background y character?

    ControllerCharacter* controllerCharacter = new ControllerCharacter(gameObjects[3], 1200, 700, 30); //ver tema pasar info size ventana.
    ControllerBackground* controllerGalaxia = new ControllerBackground(gameObjects[0], controllerCharacter, 8);
    ControllerBackground* controllerLuna = new ControllerBackground(gameObjects[1], controllerCharacter, 19);
    ControllerBackground* controllerPiso = new ControllerBackground(gameObjects[2], controllerCharacter, 30);


    controllers = { controllerGalaxia, controllerLuna, controllerPiso, controllerCharacter};

    return controllers;
}