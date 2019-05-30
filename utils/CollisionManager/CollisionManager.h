//
// Created by arielpm on 30/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_COLLISIONMANAGER_H
#define TALLER_MARVEL_CAPCOM_COLLISIONMANAGER_H


#include "../../Server/GameObject_server/GameObject_server.h"
#include "../../Server/Character_server/Character_server.h"


class CollisionManager {

public:

    CollisionManager();
    ~CollisionManager();

    bool Collisioning(GameObject_server *character1, GameObject_server *character2);
};


#endif //TALLER_MARVEL_CAPCOM_COLLISIONMANAGER_H
