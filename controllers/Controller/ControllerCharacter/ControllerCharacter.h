//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper_player/EventToValueMapper.h"
#include "../../../model/GameObjects/Character/Character.h"

using namespace std;

class ControllerCharacter : public Controller{


public:
    ControllerCharacter(GameObject *gameObject, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_, int speedCharacter_, int speedCharacter);
    ~ControllerCharacter();
    void handleEvent(SDL_Event event);
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();
    EventToValueMapper* getMapper();

    void move(DirectionVector *pVector);

    void flip(SDL_RendererFlip);

    void changePosition(int changeX, int changeY);

    bool isInAir();

    void gone();

    void entry();

    bool isChanging();

    bool isMovingRight();

    bool isMovingLeft();

private:

    EventToValueMapper* mapper;
    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft, leaving, entering, crowchedDown, movingRight, movingLeft, moving;
    string state = "still";
    CLogger* logger = CLogger::GetLogger();
    Character* character = dynamic_cast<Character*>(gameObject);


};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
