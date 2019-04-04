//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"


ControllerCharacter::ControllerCharacter(GameObject* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_) : Controller(gameObject){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_; //Despues hay que separarlo en X e Y
    jump = jumpRight = jumpLeft = inAir = false;

}

ControllerCharacter::~ControllerCharacter() = default;


void ControllerCharacter::handleEvent(SDL_Event event) {

    vector<int> dir = {0, 0, 0};
    dir = mapper->map(event, dir);
    vector<int> info = gameObject->getInfo();

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= distanceBoundaryHorizontal;

    if ( (dir[0] == RIGHT and characterIsntInRightBoundary and !inAir) or
        (dir[0] == LEFT and characterIsntInLeftBoundary and !inAir) ) {

        dir[0] *= speedCharacter;
        gameObject->move(dir);
    }

    if (dir[2] == RIGHT_DIAGONAL and !inAir) jumpRight = true;

    if (dir[2] == LEFT_DIAGONAL and !inAir) jumpLeft = true;

    if (dir[1] == UP and !inAir) jump = true;


    if ( jump ) {

        inAir = true;

        vector<int> step = {0, -jumpSpeed};

        if ( jumpRight and characterIsntInRightBoundary ) step[0] = jumpSpeed / 2;

        if ( jumpLeft and characterIsntInLeftBoundary ) step[0] = -jumpSpeed / 2;

        gameObject->move(step);

        bool characterTopOfJump = info[1] <= jumpDistance;

        if ( characterTopOfJump ) jump = false;
    }

    if ( !jump and inAir ) {

        vector<int> step = {0, jumpSpeed};

        if ( jumpRight and characterIsntInRightBoundary ) step[0] = jumpSpeed / 2;

        if ( jumpLeft and characterIsntInLeftBoundary ) step[0] = -jumpSpeed / 2;

        gameObject->move(step);

        bool characterInFloor = info[1] >= (screenHeight - info[3] - jumpDistance);

        if ( characterInFloor ) inAir = jumpRight = jumpLeft = false;
    }
}

bool ControllerCharacter::isJumping() {
    return inAir;
}

bool ControllerCharacter::isJumpingRight() {
    return jumpRight;
}

bool ControllerCharacter::isJumpingLeft() {
    return jumpLeft;
}
