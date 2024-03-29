//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H

#include "../GameObjectServerFactory/GameObjectServerFactory.h"
#include <vector>
#include "../../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include "../../GameObjects_fight/GameObject/GameObject.h"
#include "../../../utils/Mapper/Mapper_fight/Mapper_fight_1.h"
#include "../../../utils/Mapper/Mapper_fight/Mapper_fight_2.h"
#include "../../../utils/Mapper/Mapper_fight/Mapper_fight.h"

class GameObjectControllerFactory {

public:
    GameObjectControllerFactory(int screenWidth_, int screenHeight_, int speedCharacter_, int jumpSpeed_);
    ~GameObjectControllerFactory();

    vector<Controller*> getGameObjectControllers_fight(); // los controllers de la ViewController fight
    std::vector<ControllerCharacter*> getControllersCharacter_fight();
    std::vector<ControllerBackground*> getControllersBackground_fight();

private:

    int speedCharacter, jumpSpeed;

    GameObjectServerFactory* factory;
    int screenWidth, screenHeight;


};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
