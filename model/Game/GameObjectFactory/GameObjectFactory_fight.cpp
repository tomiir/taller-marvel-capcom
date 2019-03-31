//
// Created by magali on 31/03/19.
//

#include "GameObjectFactory_fight.h"



//GameObjectFactory_fight::~GameObjectFactory_fight() = default;


GameObjectFactory_fight::GameObjectFactory_fight(SDL_Renderer *renderer) {

   gameObjects [4];

    Character* character = new Character("Images/capComSprites/capCom_walk_1.png", renderer, 400, 300, 50, 120);
    if (!character) {
        //lanzar excepcion
    }

    Background* sky = new Background("Images/Backgrounds/Sky.png", renderer, 0, 0, 800, 600, 10);
    if (!sky) {
        //lanzar excepcion
    }

    Background* buildings = new Background("Images/Backgrounds/Buildings.png", renderer, 0, 0, 800, 600, 20);
    if (!buildings) {
        //lanzar excepcion
    }

    Background* street = new Background("Images/Backgrounds/Street.png", renderer, 0, 0, 800, 600, 25);
    if (!street) {
        //lanzar excepcion
    }

    gameObjects[0] = character;
    gameObjects[1] = sky;
    gameObjects[2] = buildings;
    gameObjects[3] = street;

}



