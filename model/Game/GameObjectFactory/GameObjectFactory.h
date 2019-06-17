//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H

#include "../../GameObjects_fight/Character/Character.h"
#include "../../GameObjects_fight/Background/Background.h"
#include "../../GameObjects_fight/GameObject/GameObject.h"
#include "../../GameObject_charSelect/GameObject_charSelect.h"
#include "../../../utils/LifeManager/LifeManager.h"
#include "../../../utils/TimeManager/TimeManager.h"

#include <iostream>



/* Esta se encarga de crear todos los gameObject del juego. Devuelve una lista de gameObjects */

class GameObjectFactory {

    SDL_Renderer* renderer;

public:

    GameObjectFactory(SDL_Renderer *renderer_, int screenWidth_, int screenHeight_);
    ~GameObjectFactory();

    vector<GameObject*> getGameObjectsCharacters_fight();
    vector<GameObject*> getGameObjectsBackgrounds_fight();
    vector<GameObject_charSelect*> getgameobjectChar_select_fight();
    LifeManager* getLifeManagerTeam1();
    LifeManager* getLifeManagerTeam2();
    TimeManager* getTimeManager();
    GameObject *getGameObjectDisconnected();
    vector <GameObject*> getGameObject_endGame();

private:
    bool existFile(const char* path);
    int screenWidth, screenHeight;

    int getXCenter(int width);
    int getYCenter(int height);

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
