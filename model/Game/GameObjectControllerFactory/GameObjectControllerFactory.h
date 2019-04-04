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

public:
    GameObjectControllerFactory(SDL_Renderer *renderer, int screenWidth_, int screenHeight_);
    ~GameObjectControllerFactory();

    vector<Controller*> getGameObjectControllers_fight(); // los controllers de la view fight

private:
    GameObjectFactory* factory;
    int screenWidth, screenHeight;
    double cameraSpeedPercentage(int widthMax, int widthImg);

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTCONTROLLERFACTORY_H
