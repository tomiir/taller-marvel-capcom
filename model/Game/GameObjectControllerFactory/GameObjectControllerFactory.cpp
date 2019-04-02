//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory.h"


GameObjectControllerFactory::GameObjectControllerFactory(SDL_Renderer *renderer){
    factory = new GameObjectFactory(renderer);
}

std::vector<Controller*> GameObjectControllerFactory::getGameObjectControllers_fight(){

    std::vector<GameObject*> gameObjects = factory->getGameObjects_fight();
    std::vector <Controller*> controllers;


    
    // ¿habría que hacer controllers distintos para background y character? 
    controllers = {new Controller(gameObjects[0]), new Controller(gameObjects[1]) , new Controller(gameObjects[2]),new Controller(gameObjects[3])};  // character

    return controllers;
}