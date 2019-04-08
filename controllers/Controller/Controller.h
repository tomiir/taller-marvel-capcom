//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects/GameObject/GameObject.h"
#include "../../utils/EventToValueMapper/EventToValueMapper.h"

using namespace std;

class Controller{

protected:
    GameObject * gameObject;
    EventToValueMapper* mapper;

    DirectionVector* RIGHT = new DirectionVector(1, 0);
    DirectionVector* LEFT = new DirectionVector(-1, 0);
    DirectionVector* UP = new DirectionVector(0, -1);
    DirectionVector* DOWN = new DirectionVector(0, 1);

    DirectionVector* DIAGONAL_UP_RIGHT = new DirectionVector(1, -1);
    DirectionVector* DIAGONAL_UP_LEFT = new DirectionVector(-1, -1);

    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    int jumpSpeed = 10;


public:
    Controller(GameObject* gameObject_, EventToValueMapper* mapper_);
    ~Controller();

    void render();
    virtual void handleEvent(SDL_Event event);
    vector<int> getInfo();

    };


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
