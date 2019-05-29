//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"
#include <chrono>
#include <thread>
#include "../../../utils/Logger/Logger.h"

ControllerCharacter::ControllerCharacter(GameObject_server* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_, int jumpSpeed) : Controller(gameObject, jumpSpeed){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_;
    jump = jumpRight = jumpLeft = inAir = leaving = entering = crowchedDown = movingRight = movingLeft = moving = false;

}

ControllerCharacter::~ControllerCharacter() = default;


DirectionVector* giveDirectionVect(string event){

    DirectionVector* direction = new DirectionVector();

    if (event == "h"){
      direction->add(0, 0);
    }
    else if (event == "d") {
        direction->add(1, 0);
    }
    else if (event == "a") {
        direction->add(-1, 0);
    }
    else if (event == "w") {
        direction->add(0, -1);
    }
    else if (event == "s") {
        direction->add(0, 1);
    }
    else if (event == "c") {
        direction->add(4, 0);
    }
    else if (event == "e") {
        direction->setDiagonal(1);
        direction->setY(-1);
    }
    else if (event == "q"){
        direction->setDiagonal(-1);
        direction->setY(-1);
    }
    else if (event == "r"){
        direction->add(0, 2);
    }
    else if (event == "t"){
        direction->add(-2, 0);
    }
    else if (event == "y"){
        direction->add(2, 0);
    }

    return direction;
}



void ControllerCharacter::handleEvent(string event) {

    DirectionVector* direction = giveDirectionVect(event);

    vector<int> info = gameObject->getInfo();


    if(direction->isEqual(RIGHT) and !inAir and !crowchedDown) {
        state = "walk";
        movingRight = true;
    }
    if(direction->isEqual(LEFT) and !inAir and !crowchedDown) {
        state = "walk";
        movingLeft = true;
    }
    if( direction->isEqual(DOWN) and !inAir) {
        if(state != "crowchedDown") logger->Log("El personaje " + character->getName() + " se agacho.", DEBUG, "" );
        state = "crowchedDown";
        crowchedDown = true;
    }

    if (direction->isEqual(GETTINGUP)) {
        state = "still";
        crowchedDown = false;
    }
    if (direction->isEqual(STOPRIGHT) || inAir) {
        movingRight = false;
        state = "still";
    }
    if (direction->isEqual(STOPLEFT)  || inAir) {
        movingLeft = false;
        state = "still";
    }
    if(direction->isEqual(KEYSRELEASED) and !inAir and !crowchedDown and !movingLeft and !movingRight) state = "still";

    bool characterIsntInRightBoundary = info[0] <= screenWidth - info[2] - distanceBoundaryHorizontal;
    bool characterIsntInLeftBoundary = info[0] >= 0;


    if (movingRight and characterIsntInRightBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and !direction->isEqual(GETTINGUP)){

        direction->setX(speedCharacter);
        logger -> LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if (movingLeft and characterIsntInLeftBoundary and !inAir and !crowchedDown and !direction->isEqual(UP) and !direction->isEqual(GETTINGUP)){

        direction->setX(-speedCharacter);
        logger -> LogMovement(character->getName(), direction, character->getInfo()[0], character->getInfo()[1]);
        gameObject->move(direction);

    }

    if( direction->isDiagonalRight() and !inAir  and !crowchedDown) jumpRight = true;
    if( direction->isDiagonalLeft() and !inAir  and !crowchedDown) jumpLeft = true;
    if( direction->isEqual(UP) and !inAir  and !crowchedDown){
        logger->Log("El personaje " + character->getName() + " salto.", DEBUG, "" );
        jump = true;
    }

    if( direction->isEqual(DOWN) and !inAir) {
        state = "crowchedDown";
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
            state = "still";
        }

    }

    if (direction->isEqual(CHANGECHARACTER) and !inAir){
        leaving = true;
        logger->Log(character->getName() + " cambio de personaje", DEBUG, "");
    }

    if (leaving){

        state = "jump";
        inAir = true;
        DirectionVector* step = new DirectionVector(0, -jumpSpeed);

        gameObject->move( step );

    }

    if (entering){
        state = "entering";
    }



    dynamic_cast<Character_server*>(gameObject)->setState(state);

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


void ControllerCharacter::move(DirectionVector *direction) {

    gameObject->move(direction);

}

void ControllerCharacter::flip(SDL_RendererFlip flip) {

    dynamic_cast<Character_server*> (gameObject)->flipSprite(flip);

}

void ControllerCharacter::changePosition(int changeX, int changeY) {

    dynamic_cast<Character_server*> (gameObject)->changePosition(changeX, changeY);

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

bool ControllerCharacter::isMovingRight() {
    return movingRight;
}

bool ControllerCharacter::isMovingLeft() {
    return movingLeft;
}

void ControllerCharacter::setInitialPos(bool left) {

    dynamic_cast<Character_server*>(gameObject)->setInitialPos(left);

}

vector<int> ControllerCharacter::getPosInfo() {
    return gameObject->getPosInfo();
}

string ControllerCharacter::getState() {
    return dynamic_cast<Character_server*>(gameObject)->getState();
}

SDL_RendererFlip ControllerCharacter::getFlip() {
    return dynamic_cast<Character_server*>(gameObject)->getFlip();
}
