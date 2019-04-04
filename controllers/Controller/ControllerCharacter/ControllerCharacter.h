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
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();

private:
    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft;

};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
