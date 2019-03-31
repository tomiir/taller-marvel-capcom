//
// Created by magali on 31/03/19.
//

#include "View.h"


View::View(){
    controllers [4];
    int cant = 0; //HAY QUE USAR UNA MALDITA LISTA, ESTO ES TAN VILLERO
}

void View::addController(Controller* controller){
    controllers[cant] = controller;
}