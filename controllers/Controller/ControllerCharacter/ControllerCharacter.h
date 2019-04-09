//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"
#include "../../BackgroundsController/BackgroundsController.h"
#include "../../../model/GameObjects/Characters/Character/Character.h"



class ControllerCharacter : public Controller{


public:
    ControllerCharacter(GameObject *gameObject, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_, int speedCharacter_);
    void handleEvent(SDL_Event event) override;
    void addBackgroundsController (BackgroundsController *backgroundsController_);
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();
    EventToValueMapper* getMapper();


private:

    EventToValueMapper* mapper;
    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft;
    string state = "still";
    BackgroundsController * backgroundsController;


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
