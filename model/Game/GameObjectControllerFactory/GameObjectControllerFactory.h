//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H

#include "../GameObjectFactory/GameObjectFactory.h"
#include "../../../controllers/Controller/Controller.h"
#include <vector>
#include "../../GameObjects/GameObject/GameObject.h"

using namespace std;

class GameObjectControllerFactory {

private:
    GameObjectFactory* factory;


public:
    GameObjectControllerFactory(SDL_Renderer *renderer);
    ~GameObjectControllerFactory();

    vector<Controller*> getGameObjectControllers_fight(); // los controllers de la view fight


};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
