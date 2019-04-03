//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
using namespace std;

class ControllerCharacter : public Controller{


public:
    ControllerCharacter(GameObject *gameObject, int screenWidth_, int screenHeight_, int speedCharacter_);
    ~ControllerCharacter();
    void handleEvent(SDL_Event event);

private:
    int screenWidth;
    int screenHeight;
    int distanceBoundary = 20;
    int speedCharacter;

};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
