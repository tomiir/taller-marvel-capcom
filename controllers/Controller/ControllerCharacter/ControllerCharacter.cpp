//
// Created by fer on 02/04/19.
//

#include "ControllerCharacter.h"


ControllerCharacter::ControllerCharacter(GameObject* gameObject, int screenWidth_, int screenHeight_,  int speedCharacter_) : Controller(gameObject){
    screenHeight = screenHeight_;
    screenWidth = screenWidth_;
    speedCharacter = speedCharacter_; //Despues hay que separarlo en X e Y
}
ControllerCharacter::~ControllerCharacter() = default;


void ControllerCharacter::handleEvent(SDL_Event event) {

    vector<int> dir = {0,0};
    dir = mapper->map(event, dir);
    vector<int> info = gameObject->getInfo();


    if((dir[0] == 1 and info[0] <= screenWidth - info[2] - distanceBoundary) or (dir[0] == -1 and info[0] >= distanceBoundary) ){
        dir[0] *= speedCharacter;
        dir[1] *= speedCharacter;
        gameObject->move(dir);
    }
}