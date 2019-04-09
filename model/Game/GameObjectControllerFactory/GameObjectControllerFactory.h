//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H

#include "../GameObjectFactory/GameObjectFactory.h"
#include <vector>
#include "../../../controllers/Controller/ControllerCharacter/ControllerCharacter.h"
#include "../../../controllers/Controller/ControllerBackground/ControllerBackground.h"
#include "../../GameObjects/GameObject/GameObject.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_player1.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_player2.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"

class GameObjectControllerFactory {

public:
    GameObjectControllerFactory(SDL_Renderer *renderer, int screenWidth_, int screenHeight_);
    ~GameObjectControllerFactory();

    vector<Controller*> getGameObjectControllers_fight(); // los controllers de la view fight
    std::vector<ControllerCharacter*> getControllersCharacter_fight();
    std::vector<ControllerBackground*> getControllersBackground_fight();

private:
    GameObjectFactory* factory;
    int screenWidth, screenHeight;
    double cameraSpeedPercentage(int widthMax, int widthImg);

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
