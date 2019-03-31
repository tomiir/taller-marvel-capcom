//
// Created by magali on 31/03/19.
//

#ifndef TALLER_MARVEL_CAPCOM_VIEW_H
#define TALLER_MARVEL_CAPCOM_VIEW_H

#include "../../controllers/Controller/Controller.h"

class View {

private:
    Controller** controllers;
    int cant;

public:
    void addController(Controller* controller);
};


#endif //TALLER_MARVEL_CAPCOM_VIEW_H
