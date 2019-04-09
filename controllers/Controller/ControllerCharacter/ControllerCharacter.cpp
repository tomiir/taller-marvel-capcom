//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"
#include "../../../model/GameObjects/Characters/Character/Character.h"


ControllerCharacter::ControllerCharacter(GameObject* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_) : Controller(gameObject){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_; //Despues hay que separarlo en X e Y
    jump = jumpRight = jumpLeft = inAir = false;

}

ControllerCharacter::~ControllerCharacter() = default;


void ControllerCharacter::handleEvent(SDL_Event event) {


    DirectionVector* direction = mapper->map(event);
    vector<int> info = gameObject->getInfo();

    //if(direction->isEqual(STILL)) state = "still";

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= distanceBoundaryHorizontal;

    if( (direction->isEqual(RIGHT) and characterIsntInRightBoundary and !inAir) or
        (direction->isEqual(LEFT) and characterIsntInLeftBoundary and !inAir) ){

        direction->multiply(speedCharacter);
        gameObject->move(direction);

        state = "walk";

    }

    if( direction->isDiagonalRight() and !inAir ) jumpRight = true;
    if( direction->isDiagonalLeft() and !inAir ) jumpLeft = true;
    if( direction->isEqual(UP) and !inAir ) jump = true;

    if( direction->isEqual(DOWN)) state = "still";

    if(jump){

        inAir = true;
        DirectionVector* step = new DirectionVector(0, -jumpSpeed);

        if( jumpRight and characterIsntInRightBoundary ) step->setX( jumpSpeed/2 );
        if( jumpLeft and characterIsntInLeftBoundary ) step->setX( -jumpSpeed/2 );

        gameObject->move( step );

        bool characterTopOfJump = info[1] <= jumpDistance;
        if( characterTopOfJump ) jump = false;
    }

    if( !jump and inAir ){

        DirectionVector* step = new DirectionVector(0, jumpSpeed);
        if( jumpRight and characterIsntInRightBoundary ) step->setX( jumpSpeed/2 );
        if( jumpLeft and characterIsntInLeftBoundary ) step->setX( -jumpSpeed/2 );

        gameObject->move(step);

        bool characterInFloor = info[1] >= (screenHeight - info[3] - jumpDistance);

        if ( characterInFloor ) inAir = jumpRight = jumpLeft = false;

    }

    dynamic_cast<Character*>(gameObject)->setState(state);

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
