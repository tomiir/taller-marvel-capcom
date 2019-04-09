//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H

#include "../GameObjectFactory/GameObjectFactory.h"
#include "../../../controllers/Controller/Controller.h"
#include <vector>
#include "../../GameObjects/GameObject/GameObject.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_player1.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_player2.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"
#include "../../../controllers/BackgroundsController/BackgroundsController.h"


using namespace std;

class GameObjectControllerFactory {

public:
    GameObjectControllerFactory(SDL_Renderer *renderer, int screenWidth_, int screenHeight_);
    ~GameObjectControllerFactory();

    vector<ControllerCharacter*> getCharacterControllers_fight(); // los controllers de la view fight

    BackgroundsController *getBackgroundsController_fight();

private:
    GameObjectFactory* factory;
    int screenWidth, screenHeight;
    double cameraSpeedPercentage(int widthMax, int widthImg);
    int speedCharacter = 30;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
