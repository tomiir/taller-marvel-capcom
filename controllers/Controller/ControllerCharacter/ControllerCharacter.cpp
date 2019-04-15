//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"
#include "../../../model/GameObjects/Character/Character.h"
#include <chrono>
#include <thread>
#include "../../../utils/Logger/Logger.h"


ControllerCharacter::ControllerCharacter(GameObject* gameObject, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_,  int speedCharacter_) : Controller(gameObject){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_; //Despues hay que separarlo en X e Y
    jump = jumpRight = jumpLeft = inAir = leaving = entering = false;
    mapper = mapper_;

}

ControllerCharacter::~ControllerCharacter() = default;


void ControllerCharacter::handleEvent(SDL_Event event) {

    CLogger* logger = CLogger::GetLogger();
    logger -> Log("Handling sth", DEBUG, "");

    DirectionVector* direction = mapper->map(event);
    vector<int> info = gameObject->getInfo();

    if(event.key.state == SDL_RELEASED and !inAir) state = "still";
    if(direction->isEqual(RIGHT)) state = "walk";
    if(direction->isEqual(LEFT)) state = "walk";


    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= 0;


    if( (direction->isEqual(RIGHT) and characterIsntInRightBoundary and !inAir) or
        (direction->isEqual(LEFT) and characterIsntInLeftBoundary and !inAir) ){

        direction->multiply(speedCharacter);
        gameObject->move(direction);

        state = "walk";

    }

    if( direction->isDiagonalRight() and !inAir ) jumpRight = true;
    if( direction->isDiagonalLeft() and !inAir ) jumpLeft = true;
    if( direction->isEqual(UP) and !inAir ) jump = true;

    if( direction->isEqual(DOWN) and !inAir) {

        state = "crowchedDown";
        gameObject->crowchDown();
    }

    if ( direction->isEqual(GETTINGUP) and !inAir) gameObject->stayInFloor();

    if(jump){

        state = "jump";
        inAir = true;
        DirectionVector* step = new DirectionVector(0, -jumpSpeed);

        if( jumpRight and characterIsntInRightBoundary ) step->setX( jumpSpeed/2 );
        if( jumpLeft and characterIsntInLeftBoundary ) step->setX( -jumpSpeed/2 );

        gameObject->move( step );

        bool characterTopOfJump = info[1] <= jumpDistance;
        if( characterTopOfJump ) jump = false;
    }

    if( !jump and inAir and !leaving){

        state = "jump";

        DirectionVector* step = new DirectionVector(0, jumpSpeed);
        if( jumpRight and characterIsntInRightBoundary ) step->setX( jumpSpeed/2 );
        if( jumpLeft and characterIsntInLeftBoundary ) step->setX( -jumpSpeed/2 );

        gameObject->move(step);

        bool characterInFloor = info[1] >= (screenHeight - info[3] - jumpDistance);

        if ( characterInFloor ) {
            inAir = jumpRight = jumpLeft = entering = false;
            gameObject->stayInFloor();
        }

    }

    if (mapper->changeCharacter(event) and !inAir) leaving = true;

    if (leaving){

        state = "jump";
        inAir = true;
        DirectionVector* step = new DirectionVector(0, -jumpSpeed);

        gameObject->move( step );

    }

    if (entering){
        state = "entering";
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

EventToValueMapper* ControllerCharacter::getMapper(){
    return mapper;
}

void ControllerCharacter::move(DirectionVector *direction) {

    gameObject->move(direction);

}

void ControllerCharacter::flip(SDL_RendererFlip flip) {

    dynamic_cast<Character*> (gameObject)->flipSprite(flip);

}

void ControllerCharacter::changePosition(int changeX, int changeY) {

    dynamic_cast<Character*> (gameObject)->changePosition(changeX, changeY);

}

bool ControllerCharacter::isInAir() {
    return inAir;
}

void ControllerCharacter::gone() {

    leaving = false;

}

void ControllerCharacter::entry() {

    entering = true;
    inAir = true;

}

bool ControllerCharacter::isChanging() {
    return (entering or leaving);
}
