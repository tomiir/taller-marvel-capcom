//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"



//GameObjectFactory_fight::~GameObjectFactory_fight() = default;


GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

std::vector<GameObject*> GameObjectFactory:: getGameObjects_fight() {
    std::vector<GameObject*>  gameObjects;

    Character* character = new Character("/home/magali/Documents/taller/taller-marvel-capcom/Images/capComSprites/capCom_walk_1.png", renderer, 400, 300, 50, 120);
    if (!character) {
        std::cout << "Fallo la creacion del render" << std::endl;
    }

    Background* sky = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Sky.png", renderer, 0, 0, 800, 600, 10);
    if (!sky) {
        //lanzar excepcion
    }

    Background* buildings = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Buildings.png", renderer, 0, 0, 800, 600, 20);
    if (!buildings) {
        //lanzar excepcion
    }

    Background* street = new Background("/home/magali/Documents/taller/taller-marvel-capcom/Images/Backgrounds/Street.png", renderer, 0, 0, 800, 600, 25);
    if (!street) {
        //lanzar excepcion
    }

    gameObjects[0] = character;
    gameObjects[1] = sky;
    gameObjects[2] = buildings;
    gameObjects[3] = street;

    return gameObjects;

}



