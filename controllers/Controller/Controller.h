//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects/GameObject/GameObject.h"
#include "../../utils/EventToValueMapper/EventToValueMapper.h"

class Controller{

private:
    GameObject * gameObject;
    EventToValueMapper* mapper;


public:
    Controller(GameObject* gameObject_);
    ~Controller();
    void render();
    void handleEvent(SDL_Event event);
};


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
