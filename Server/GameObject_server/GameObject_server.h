//
// Created by arielpm on 16/05/19.
//

#ifndef TALLER_MARVEL_CAPCOM_GAMEOBJECT_SERVER_H
#define TALLER_MARVEL_CAPCOM_GAMEOBJECT_SERVER_H

#include <string>
#include <SDL_rect.h>
#include <vector>
#include "../../utils/Vector2D/DirectionVector.h"

using namespace std;

class GameObject_server {

public:
    GameObject_server(string name, int initialX, int initialY, int width, int height);
    ~GameObject_server();

    virtual void move(DirectionVector* direction);
    virtual vector<int> getInfo();
    virtual void stayInFloor();
    string getName();


protected:
    string name;
    SDL_Rect objRect;
    int z_index;
};

#endif //TALLER_MARVEL_CAPCOM_GAMEOBJECT_SERVER_H
