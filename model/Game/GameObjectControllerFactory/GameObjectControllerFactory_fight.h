//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_FIGHT_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_FIGHT_H

#include "GameObjectControllerFactory.h"
#include "../GameObjectFactory/GameObjectFactory.h"
#include "../../../controllers/Controller/Controller.h"
#include "../GameObjectFactory/GameObjectFactory_fight.h"


class GameObjectControllerFactory_fight: public GameObjectControllerFactory {

public:
    explicit GameObjectControllerFactory_fight(SDL_Renderer *renderer);

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_FIGHT_H
