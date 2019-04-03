//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects/GameObject/GameObject.h"
#include "../../utils/EventToValueMapper/EventToValueMapper.h"

class Controller{

protected:
    GameObject * gameObject;
    EventToValueMapper* mapper;

    int RIGHT = 1;
    int LEFT = -1;


public:
    Controller(GameObject* gameObject_);
    ~Controller();
    void render();
    virtual void handleEvent(SDL_Event event);
    std::vector<int> getInfo();

    };


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
