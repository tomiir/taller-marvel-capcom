//
// Created by trocchi on 3/28/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLER_H

#include "../../model/GameObjects/GameObject/GameObject.h"

class Controller {

private:
    GameObject* gameObject;
public:
    Controller(GameObject* gameObject_);
};


#endif //TALLER_MARVEL_CAPCOM__CONTROLLER_H
