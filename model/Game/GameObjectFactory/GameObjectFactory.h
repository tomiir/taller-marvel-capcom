//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY__H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY__H

#include "../../GameObjects/GameObject/GameObject.h"


/* Esta es la interfaz de los GameFactory, se implementa con una clase abstracta*/


class GameObjectFactory{

protected:
    GameObject** gameObjects;
public:

    //~GameObjectFactory_fight();

    GameObject** getGameObjects();

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY__H
