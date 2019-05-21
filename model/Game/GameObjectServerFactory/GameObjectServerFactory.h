//
// Created by arielpm on 17/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTSERVERFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTSERVERFACTORY_H


#include <iostream>
#include "../../../Server/GameObject_server/GameObject_server.h"
#include "../../../utils/Logger/Logger.h"
#include "../../../Json/JsonConfigs.h"
#include "../../../Server/Character_server/Character_server.h"
#include "../../../Server/Background_server/Background_server.h"



/* Esta se encarga de crear todos los gameObject del juego. Devuelve una lista de gameObjects */

class GameObjectServerFactory {

public:

    GameObjectServerFactory(int screenWidth_, int screenHeight_);
    ~GameObjectServerFactory();

    vector<GameObject_server*> getGameObjectsServerCharacters_fight();
    vector<GameObject_server*> getGameObjectsServerBackgrounds_fight();


private:
    double cameraSpeedPercentage(int widthMax, int widthImg);
    int screenWidth, screenHeight;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTSERVERFACTORY_H
