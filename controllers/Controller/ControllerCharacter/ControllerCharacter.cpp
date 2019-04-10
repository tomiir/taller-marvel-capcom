//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"

#include <stdio.h>
#include <chrono>
#include <thread>



ControllerCharacter::ControllerCharacter(Character* gameObject_, EventToValueMapper* mapper_, int screenWidth_, int screenHeight_,  int speedCharacter_){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_; //Despues hay que separarlo en X e Y
    jump = jumpRight = jumpLeft = inAir = false;
    mapper = mapper_;
    gameObject = gameObject_;
}

ControllerCharacter::~ControllerCharacter() = default;



void ControllerCharacter :: flip(ControllerCharacter* enemy){
    int x_enemy = (enemy->getInfo())[0];
    int x = (gameObject->getInfo())[0];

    if( x < x_enemy){
        gameObject->flipRight();
        printf("flipea");
    }

    else{
        gameObject->flipLeft();
        printf("flipea");
    }

}

vector<int> ControllerCharacter :: getInfo(){
    return gameObject->getInfo();
}

void ControllerCharacter::handleEvent(SDL_Event event) {

    DirectionVector* direction = mapper->map(event);
    vector<int> info = gameObject->getInfo();

    if(event.key.state == SDL_RELEASED) state = "still";
    if(direction->isEqual(RIGHT)) state = "walk";
    if(direction->isEqual(LEFT)) state = "walk";


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

EventToValueMapper* ControllerCharacter::getMapper(){
    return mapper;
}

void ControllerCharacter::move(DirectionVector *direction) {

    //direction->multiply(speedCharacter);
    gameObject->move(direction);

}


void ControllerCharacter::render(){ //en vez de render tendria que ser "draw"

    gameObject->render();
}