//
// Created by magali on 31/03/19.
//

#include "GameObjectControllerFactory_fight.h"


GameObjectControllerFactory_fight::GameObjectControllerFactory_fight(SDL_Renderer *renderer){

    factory = new GameObjectFactory_fight(renderer);
    GameObject** gameObjects = factory->getGameObjects();
    controllers[4];

    controllers[0] = new Controller(gameObjects[0]); //AGREGAR ESTO A CONTROLLER, CHARACTER

    controllers[1] = new Controller(gameObjects[1]);// background
    controllers[2] = new Controller(gameObjects[2]);// buildings
    controllers[3] = new Controller(gameObjects[3]);// street

}