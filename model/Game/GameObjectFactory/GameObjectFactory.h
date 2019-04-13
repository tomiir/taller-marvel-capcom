//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H

#include "../../GameObjects/Character/Character.h"
#include "../../GameObjects/Background/Background.h"
#include "../../GameObjects/GameObject/GameObject.h"

#include <iostream>

using namespace std;


/* Esta se encarga de crear todos los gameObject del juego. Devuelve una lista de gameObjects */

class GameObjectFactory {

    SDL_Renderer* renderer;

public:

    GameObjectFactory(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_);
    ~GameObjectFactory();

    vector<GameObject*> getGameObjectsCharacters_fight();
    vector<GameObject*> getGameObjectsBackgrounds_fight();

private:

    int screenWidth, screenHeight;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
