//
// Created by fer on 02/04/19.
//

#ifndef TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
#define TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H


#include "../Controller.h"
#include "../../../utils/Vector2D/DirectionVector.h"
#include "../../../utils/EventToValueMapper/EventToValueMapper.h"
#include "../../../model/GameObjects/Characters/Character/Character.h"

using namespace std;

class ControllerCharacter{


public:
    ControllerCharacter(Character *gameObject_, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_, int speedCharacter_);
    ~ControllerCharacter();
    void handleEvent(SDL_Event event);
    bool isJumping();
    bool isJumpingRight();
    bool isJumpingLeft();
    EventToValueMapper* getMapper();

    void move(DirectionVector *pVector);
    void render();
    void flip(ControllerCharacter* enemy);

    vector<int> getInfo();

private:
    DirectionVector* RIGHT = new DirectionVector(1, 0);
    DirectionVector* LEFT = new DirectionVector(-1, 0);
    DirectionVector* UP = new DirectionVector(0, -1);
    DirectionVector* DOWN = new DirectionVector(0, 1);
    DirectionVector* STILL = new DirectionVector(0, 0);

    DirectionVector* DIAGONAL_UP_RIGHT = new DirectionVector(1, -1);
    DirectionVector* DIAGONAL_UP_LEFT = new DirectionVector(-1, -1);

    int distanceBoundaryHorizontal = 25;
    int distanceBoundaryVertical = 75;
    int jumpSpeed = 10;

    EventToValueMapper* mapper;
    int screenWidth, screenHeight, speedCharacter;
    int jumpDistance = 10;
    bool jump, inAir, jumpRight, jumpLeft;
    string state = "still";
    Character* gameObject;

};


#endif //TALLER_MARVEL_CAPCOM_CONTROLLERCHARACTER_H
