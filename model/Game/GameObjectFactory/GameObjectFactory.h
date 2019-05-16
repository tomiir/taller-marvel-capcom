//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H

#include "../../GameObjects_fight/Character/Character.h"
#include "../../GameObjects_fight/Background/Background.h"
#include "../../GameObjects_fight/GameObject/GameObject.h"
#include "../../GameObject_charSelect/GameObject_charSelect.h"

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


private:
    double cameraSpeedPercentage(int widthMax, int widthImg);
    bool existFile(const char* path);
    int screenWidth, screenHeight;

};


#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECTFACTORY_H
