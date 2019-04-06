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

    int RIGHT = 1;
    int LEFT = -1;
    int UP = -1;
    int DOWN = 1;
    int RIGHT_DIAGONAL = 1;
    int LEFT_DIAGONAL = -1;

    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    int jumpSpeed = 10;


public:
    Controller(GameObject* gameObject_);
    ~Controller();
    void render();
    virtual void handleEvent(SDL_Event event);
    vector<int> getInfo();

    };


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
