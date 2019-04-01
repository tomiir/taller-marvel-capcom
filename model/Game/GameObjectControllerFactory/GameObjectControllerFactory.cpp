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
    controllers[0] = new Controller(gameObjects[0]); // character

    controllers[1] = new Controller(gameObjects[1]);// background
    controllers[2] = new Controller(gameObjects[2]);// buildings
    controllers[3] = new Controller(gameObjects[3]);// street
    
    
    return controllers;
}