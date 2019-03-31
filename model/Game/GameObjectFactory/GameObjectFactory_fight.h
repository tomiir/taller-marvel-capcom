//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H

#include "../../GameObjects/Characters/Character/Character.h"
#include "../../GameObjects/Background/Background.h"
#include "../../GameObjects/GameObject/GameObject.h"
#include "GameObjectFactory.h"

/* Esta se encarga de crear todos los gameObject del juego. Devuelve una lista de gameObjects */

class GameObjectFactory_fight: public GameObjectFactory{


public:
    GameObjectFactory_fight(SDL_Renderer *renderer);

    //~GameObjectFactory_fight();

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
