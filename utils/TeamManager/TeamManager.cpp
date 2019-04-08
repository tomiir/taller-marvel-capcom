//
// Created by magali on 08/04/19.
//

#include "TeamManager.h"

TeamManager::TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, EventToValueMapper* mapper_){
    mapper = mapper_;
    currentCharacter = character_1;
    postCharacter = character_2;
}

void TeamManager::changeCharacter(){
    ControllerCharacter* aux;
    aux = currentCharacter;
    currentCharacter = postCharacter;
    postCharacter = aux;
}

void TeamManager::handleEvent(SDL_Event event){

    if(mapper->changeCharacter(event)){
        changeCharacter();
    }
    else{
        currentCharacter->handleEvent(event);
    }
}