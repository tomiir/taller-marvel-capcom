//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H

#include "../../GameObjects/Characters/Character/Character.h"
#include "../../GameObjects/Background/Background.h"
#include "../../GameObjects/GameObject/GameObject.h"

#include <iostream>

using namespace std;


/* Esta se encarga de crear todos los gameObject del juego. Devuelve una lista de gameObjects */

class GameObjectFactory {

    SDL_Renderer* renderer;

public:

    GameObjectFactory(SDL_Renderer *renderer_);
    ~GameObjectFactory();

    vector<GameObject*> getGameObjectsCharacters_fight();
    vector<GameObject*> getGameObjectsBackgrounds_fight();


};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
