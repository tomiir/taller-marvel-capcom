//
// Created by magali on 08/04/19.
//

#include "TeamManager.h"

TeamManager::TeamManager(ControllerCharacter* character_1, ControllerCharacter* character_2, EventToValueMapper* mapper_){
    mapper = mapper_;
    currentCharacter = character_1;
    supportCharacter = character_2;
}

void TeamManager::changeCharacter(){
    ControllerCharacter* aux;
    aux = currentCharacter;
    currentCharacter = supportCharacter;
    supportCharacter = aux;
}

void TeamManager::handleEvent(SDL_Event event){

    currentCharacter->handleEvent(event);
    if (currentCharacter.getMapper()->changeCharacter(event)){
        changeCharacter();
    }
}