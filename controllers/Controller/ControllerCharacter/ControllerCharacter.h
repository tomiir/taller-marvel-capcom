//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"
#include "../../BackgroundsController/BackgroundsController.h"

using namespace std;

class ControllerCharacter : public Controller{


public:
    ControllerCharacter(GameObject *gameObject, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_, int speedCharacter_);
    ~ControllerCharacter();
    void handleEvent(SDL_Event event);
    EventToValueMapper* mapper;
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();
    EventToValueMapper* getMapper();
    void render();

private:

    EventToValueMapper* mapper;
    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft;
    string state = "still";


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
