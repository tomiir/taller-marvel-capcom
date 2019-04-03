//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory.h"





GameObjectFactory::GameObjectFactory(SDL_Renderer *renderer_) {

    renderer = renderer_;

}

GameObjectFactory::~GameObjectFactory() = default;


std::vector<GameObject*> GameObjectFactory:: getGameObjects_fight() {
    std::vector<GameObject*>  gameObjects;

    Character* character = new Character("/home/fer/taller-marvel-capcom/Images/capComSprites/capCom_walk_1.png", renderer, 400, 400, 200, 300);
    if (!character) {
        std::cout << "Fallo la creacion del render" << std::endl;
    }

    Background* B1 = new Background("/home/fer/taller-marvel-capcom/Images/Backgrounds/Background1.png", renderer, 1500, 900, 1200, 700);
    if (!B1) {
        //lanzar excepcion
    }

    Background* B2 = new Background("/home/fer/taller-marvel-capcom/Images/Backgrounds/Background2.png", renderer, 1900, 900, 1200, 700);
    if (!B2) {
        //lanzar excepcion
    }

    Background* B3 = new Background("/home/fer/taller-marvel-capcom/Images/Backgrounds/Background3.png", renderer, 2300, 900, 1200, 700);
    if (!B3) {
        //lanzar excepcion
    }

    gameObjects = {B1, B2, B3, character};


    return gameObjects;

}



